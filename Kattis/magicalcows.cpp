#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int C, N, M; cin >> C >> N >> M;

    vector<vector<long>> dp;

    dp.resize(51, vector<long>(C+1, 0));

    int cow;
    for (int i = 0; i < N; ++i) {
        cin >> cow;
        dp[0][cow] += 1;
    }

    for (int day = 0; day < 50; ++day) {
        for (int i = 1; i <= C; ++i) {
            if (i <= C/2) dp[day+1][2*i] += dp[day][i];
            else dp[day+1][i] += 2*dp[day][i];
        }
    }

    int day;
    for (int i = 0; i < M; ++i) {
        cin >> day;
        long farms = 0;
        for (int j = 0; j <= C; ++j) farms += dp[day][j];
        cout << farms << endl;
    }

    return 0;
}