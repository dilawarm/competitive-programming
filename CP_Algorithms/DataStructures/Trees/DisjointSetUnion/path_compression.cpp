#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] == find_set(parent[v]);
}