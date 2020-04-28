#include<bits/stdc++.h>
using namespace std;

bool isPowerOfThree(int n) {
    return 1162261467 % 3 == 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n = 27;
    cout << isPowerOfThree(n);
    return 0;
}