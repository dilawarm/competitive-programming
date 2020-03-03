#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    string ans = to_string(n) + " ";
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
            ans += to_string(n) + " ";
        }
        else {
            n = 3*n + 1;
            ans += to_string(n) + " ";
        }
    }
    cout << ans << endl;
    return 0;
}