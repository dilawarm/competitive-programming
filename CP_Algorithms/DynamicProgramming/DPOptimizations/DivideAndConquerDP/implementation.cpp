#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9;

int n;
long long C(int i, int j);
vector<long long> dp_before(n), dp_cur(n);

// dp(i, j) = min_{k\leq j}{dp(i-1, k) + C(k, j)}

// compute dp_cur[l], ..., dp_cur[r] (inclusive)
void compute(int l, int r, int optl, int optr)
{
    if (l > r)
        return;
    int mid = (l + r) >> 1;
    pair<long long, int> best = {INF, -1};

    for (int k = optl; k <= min(mid, optr); k++)
    {
        best = min(best, {dp_before[k] + C(k, mid), k});
    }

    dp_cur[mid] = best.first;
    int opt = best.second;

    compute(l, mid - 1, optl, opt);
    compute(mid + 1, r, opt, optr);
}