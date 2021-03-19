#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> index;

void make_set(int v)
{
    parent[v] = v;
    index[v] = rand();
}

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
        if (index[a] < index[b])
            swap(a, b);
        parent[b] = a;
    }
}
