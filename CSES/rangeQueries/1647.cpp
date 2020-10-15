/*
Given an array of n integers, your task is to process q queries of the form: what is the minimum value in range [a,b]?
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

class SegmentTree
{
public:
    SegmentTree(int n_);
    void increment(int a, int b, int val);
    int minimum(int a, int b);

private:
    int n;
    std::vector<int> lo, hi, min, delta;

    void increment(int i, int a, int b, int val);
    int minimum(int i, int a, int b);
    void init(int i, int a, int b);
    void prop(int i);
    void update(int i);
};

SegmentTree::SegmentTree(int n_)
{
    n = n_;
    lo.assign(4 * n + 1, 0);
    hi.assign(4 * n + 1, 0);
    min.assign(4 * n + 1, 0);
    delta.assign(4 * n + 1, 0);

    init(1, 0, n - 1);
}

void SegmentTree::increment(int a, int b, int val)
{
    increment(1, a, b, val);
}

int SegmentTree::minimum(int a, int b)
{
    return minimum(1, a, b);
}

void SegmentTree::init(int i, int a, int b)
{
    lo[i] = a;
    hi[i] = b;

    if (a == b)
        return;

    int m = (a + b) / 2;
    init(2 * i, a, m);
    init(2 * i + 1, m + 1, b);
}

void SegmentTree::prop(int i)
{
    delta[2 * i] += delta[i];
    delta[2 * i + 1] += delta[i];
    delta[i] = 0;
}

void SegmentTree::update(int i)
{
    min[i] = std::min(min[2 * i] + delta[2 * i], min[2 * i + 1] + delta[2 * i + 1]);
}

void SegmentTree::increment(int i, int a, int b, int val)
{
    if (b < lo[i] || hi[i] < a)
        return;

    if (a <= lo[i] && hi[i] <= b)
    {
        delta[i] += val;
        return;
    }

    prop(i);

    increment(2 * i, a, b, val);
    increment(2 * i + 1, a, b, val);

    update(i);
}

int SegmentTree::minimum(int i, int a, int b)
{
    if (b < lo[i] || hi[i] < a)
        return std::numeric_limits<int>::max();

    if (a <= lo[i] && hi[i] <= b)
        return min[i] + delta[i];

    prop(i);

    int minLeft = minimum(2 * i, a, b);
    int minRight = minimum(2 * i + 1, a, b);

    update(i);

    return std::min(minLeft, minRight);
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie();

    int n, q, x, a, b;
    std::cin >> n >> q;
    SegmentTree st(n);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> x;
        st.increment(i, i, x);
    }

    for (int i = 0; i < q; ++i)
    {
        std::cin >> a >> b;
        std::cout << st.minimum(--a, --b) << "\n";
    }

    return 0;
}