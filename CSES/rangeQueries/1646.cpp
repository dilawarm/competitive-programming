/*
Given an array of n integers, your task is to process q queries of the form: what is the sum of values in range [a,b]?
*/
#include <iostream>
#include <vector>

using namespace std;

vector<long long> fenwick_tree;

int lsb(int i)
{
    return i & (-i);
}

long long sum(int index)
{
    long long sum = 0;
    for (; index > 0; index -= lsb(index))
        sum += fenwick_tree[index];
    return sum;
}

void add(size_t index, long long value)
{
    for (; index < fenwick_tree.size(); index += lsb((int)index))
        fenwick_tree[index] += value;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    fenwick_tree = vector<long long>(n + 1);
    long long value;

    for (int i = 0; i < n; ++i)
    {
        cin >> value;
        add((size_t)i + 1, value);
    }

    int a, b;
    for (int i = 0; i < q; ++i)
    {
        cin >> a >> b;
        cout << sum(b) - sum(a - 1) << "\n";
    }

    return 0;
}