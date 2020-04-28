#include<bits/stdc++.h>
using namespace std;

int climbStairs(int n) {
    vector<int> dp(n+1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < 3; ++j) {
            if (i - j >= 0) dp[i] += dp[i-j];
        }
    }
    return dp[n];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n = 5;
    cout << climbStairs(n) << endl;
    return 0;
}