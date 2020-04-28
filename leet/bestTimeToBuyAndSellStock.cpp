#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices) {
    int n = prices.size();
    int profit = INT_MIN;
    int buy = prices[0];
    for (int i = 0; i < n; ++i) {
        profit = max(profit, prices[i] - buy);
        buy = min(buy, prices[i]);
    }
    return profit;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    vector<int> prices{7,2,5,1,6,4};
    cout << maxProfit(prices) << endl;
    return 0;
}