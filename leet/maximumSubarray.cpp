#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums) {
    int kadane = 0;
    int m = 0;
    for (int i = 0; i < nums.size(); ++i) {
        m += nums[i];
        if (m < 0) m = 0;
        else if (kadane < m) kadane = m;
    }
    return kadane;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums) << endl;
    return 0;
}