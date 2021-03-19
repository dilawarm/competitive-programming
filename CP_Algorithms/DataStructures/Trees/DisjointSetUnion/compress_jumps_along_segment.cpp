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

struct Point
{
    int l;
    int r;
    int c;
};

int main()
{
    int L, m;
    vector<Point> query;
    vector<int> answer;

    for (int i = 0; i <= L; i++)
        make_set(i);

    for (int i = m - 1; i >= 0; i--)
    {
        int l = query[i].l;
        int r = query[i].r;
        int c = query[i].c;

        for (int v = find_set(l); v <= r; v = find_set(v))
        {
            answer[v] = c;
            parent[v] = v + 1;
        }
    }
}