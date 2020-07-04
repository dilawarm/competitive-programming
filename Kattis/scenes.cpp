#include <iostream>
#include <algorithm>

using namespace std;

int n, w, h;
long DP[101][10001];
long MOD = 1000000007;

long solve(int width, int r) {
    if (r < 0) return 0;
    if (width > w) return 1;
    if (DP[width][r]) return DP[width][r];

    long mountains = 0;
    for (int i = 0; i <= h; ++i) mountains += solve(width +  1, r - i);

    return DP[width][r] = mountains % MOD;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> w >> h;

    int rs = min(w*h, n);
    int p = (rs / w) + 1;

    long mountains = ((solve(1, n) - p) + MOD) % MOD;
    cout << mountains;
}