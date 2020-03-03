#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, x, p_i; cin >> n >> x;
    vector<int> w;
    for (int i = 0; i < n; ++i) {
        cin >> p_i;
        w.push_back(p_i);
    }
    sort(w.begin(), w.end());

    int l = 0, r = n-1, ans = 0;
    while (l <= r) {
        if (w[l] + w[r] <= x) {
            ++l;
            r--;
        }
        else r--;
        ++ans;
    }
    cout << ans << endl;
}