#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> parent;
vector<int> _rank;

void make_set(int v)
{
    parent[v] = make_pair(v, 0);
    _rank[v] = 0;
}

pair<int, int> find_set(int v)
{
    if (v != parent[v].first)
    {
        int len = parent[v].second;
        parent[v] = find_set(parent[v].first);
        parent[v].second += len;
    }
    return parent[v];
}

void union_sets(int a, int b)
{
    a = find_set(a).first;
    b = find_set(b).second;
    if (a != b)
    {
        if (_rank[a] < _rank[b])
            swap(a, b);
        parent[b] = make_pair(a, 1);
        if (_rank[a] == _rank[b])
            _rank[a]++;
    }
}