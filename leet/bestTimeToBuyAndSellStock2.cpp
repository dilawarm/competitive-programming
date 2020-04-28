#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices) {
    int n = prices.size();
    int profit = 0;
    int i = 0;
    while (i < n-1) {
        if (prices[i] < prices[i+1]) {
            int j = i+1;
            while (j < n) {
                if (prices[j] > prices[j+1]) {
                    profit += prices[j] - prices[i];
                    break;
                } else {
                    ++j;
                }
            }
            i = j + 1;
        } else {
            ++i;
        }
    }
    return profit;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    vector<int> prices{1,2,3,4,5};
    cout << maxProfit(prices) << endl;
}