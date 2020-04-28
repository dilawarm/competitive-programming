#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

void rotate(vector<int> &nums, int k) {
    int n = nums.size();
    int g = gcd(n, k+1);
    for (int i = 0; i < g; ++i) {
        int temp = nums[i];
        int j = i;

        while (1) {
            if ((j+k+1)%n == i) break;
            nums[j] = nums[(j+k+1)%n];
            j = (j+k+1)%n;
        }
        nums[j] = temp;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    vector<int> nums{1,2,3,4,5,6,7};
    rotate(nums, 3);
    for (int i = 0; i < nums.size(); ++i) cout << nums[i] << " ";
    return 0;
}