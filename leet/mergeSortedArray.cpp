#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m-1;
    int j = n-1;
    int k = m+n-1;

    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
        else nums1[k--] = nums2[j--];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    vector<int> nums1{1,2,3,0,0,0};
    int m = 3;
    vector<int> nums2{2,5,6};
    int n = 3;
    
    merge(nums1, m, nums2, n);
    for (int i = 0; i < n+m; ++i) cout << nums1[i] << " ";
    return 0;
}