#include<bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> &arr, int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return true;
        if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return false;
}

int main() {
    vector<int> nums;
    int n; cin >> n;
    int x;
    for (int i = 0; i < n-1; ++i) {
        cin >> x;
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());
    for (int i = 1; i <= n; ++i) {
        if (!binarySearch(nums, 0, n-1, i)) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}