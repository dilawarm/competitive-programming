#include<bits/stdc++.h>
using namespace std;

int reverse(int x) {
    string s = to_string(x);
    int n = s.size();

    if ((n-1)%2 == 0) {
        for (int i = 0; i < (n-1)/2; ++i) {
            swap(s[i], s[n-1-i]);
        }
    } else {
        for (int i = 0; i < n/2; ++i) {
            swap(s[i], s[n-1-i]);
        }
    }

    if (s[n-1] == '-') return -stoi(s);
    return stoi(s);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int x = -123;
    cout << reverse(x) << endl;
}