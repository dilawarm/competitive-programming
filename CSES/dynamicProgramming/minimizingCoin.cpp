#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, x; cin >> n >> x;
    vector<int> c(n), dp(x+1, 1e9+1);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) cin >> c[i];
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i - c[j] >= 0) dp[i] = min(dp[i], dp[i-c[j]]+1);
        }
    }
    cout << (dp[x] == 1e91+1 ? -1 : dp[x]) << endl;
    return 0; 
}