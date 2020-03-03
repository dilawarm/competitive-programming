#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    long long prev; cin >> prev;
    long long x, ans = 0;
    for (int i = 0; i < n-1; ++i) {
        cin >> x;
        if (x < prev) {
            ans += prev - x;
            long long inc = prev - x;
            x += inc;
        }
        prev = x;
    }
    cout << ans << endl;
}