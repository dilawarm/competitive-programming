#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> size;

void make_set(int v)
{
    parent[v] = v;
    size[v] = 1;
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
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

struct Query
{
    int L, R, idx;
};

vector<int> answer;
vector<int> a;
vector<vector<Query>> container;

int main()
{
    int n;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && a[s.top()] > a[i])
        {
            parent[s.top()] = i;
            s.pop();
        }
        s.push(i);
        for (Query q : container[i])
        {
            answer[q.idx] = a[find_set(q.L)];
        }
    }
}