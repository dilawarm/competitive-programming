/*
Given an array of n integers, your task is to process q queries of the following types:

    1. update the value at position k to u

    2. what is the sum of values in range [a,b]?
*/
#include <iostream>
#include <vector>

std::vector<long long> fenwick_tree;

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

void update(int index, long long value)
{
    add((size_t)index, sum(index - 1) - sum(index));
    add((size_t)index, value);
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, q;
    std::cin >> n >> q;

    fenwick_tree = std::vector<long long>(n + 1);
    long long value;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> value;
        add((size_t)i + 1, value);
    }

    int a, b, c;
    for (int i = 0; i < q; ++i)
    {
        std::cin >> c;
        if (c == 1)
        {
            std::cin >> a >> value;
            update(a, value);
        }
        else
        {
            std::cin >> a >> b;
            std::cout << sum(b) - sum(a - 1) << "\n";
        }
    }

    return 0;
}