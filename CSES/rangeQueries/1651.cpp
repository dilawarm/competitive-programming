/*
Given an array of n integers, your task is to process q queries of the following types:

    1. increase each value in range [a,b] by u
    2. what is the value at position k ?
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

void update(int index, int end, long long value)
{
    add((size_t)index, value);
    add((size_t)end + 1, -value);
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
        update((size_t)i + 1, i + 1, value);
    }

    int a, b, c;
    for (int i = 0; i < q; ++i)
    {
        std::cin >> c;
        if (c == 1)
        {
            std::cin >> a >> b >> value;
            update(a, b, value);
        }
        else
        {
            std::cin >> a;
            std::cout << sum(a) << "\n";
        }
    }

    return 0;
}