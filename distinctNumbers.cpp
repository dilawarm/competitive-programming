#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    map<int, int> seen;
    int n; cin >> n;
    int x, ans = 0;;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (seen.count(x) == 0) {
            ++ans;
            seen[x] = 1;
        }
    }
    cout << ans << endl;
    return 0;
}