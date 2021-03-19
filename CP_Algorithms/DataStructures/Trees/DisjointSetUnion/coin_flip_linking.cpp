#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] == find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (rand() % 2)
            swap(a, b);
        parent[b] = a;
    }
}
