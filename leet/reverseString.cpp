#include<bits/stdc++.h>
using namespace std;

void reverseString(string &s) {
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
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string s = "Hannah";
    reverseString(s);
    for (int i = 0; i < s.size(); ++i) cout << s[i];
}