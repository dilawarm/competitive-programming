#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> _rank;

void make_set(int v)
{
    parent[v] = v;
    _rank[v] = 0;
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
        if (_rank[a] < _rank[b])
            swap(a, b);
        parent[b] = a;
        if (_rank[a] == _rank[b])
            _rank[a]++;
    }
}
