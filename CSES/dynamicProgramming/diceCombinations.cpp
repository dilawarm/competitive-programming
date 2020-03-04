#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> dp(n+1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int s = max(0, i - 6);
        for (int j = s; j < i; ++j) {
            dp[i] += dp[j];
            dp[i] %= 1000000007;
        }
    }
    cout << dp[dp.size()-1] << endl;
    return 0;
}