#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    multiset<int, greater<int>> h;
    int hi;
    for (int i = 0; i < n; ++i) {
        cin >> hi;
        h.insert(hi);
    }

    int ti;
    for (int i = 0; i < m; ++i) {
        cin >> ti;
        auto it = h.lower_bound(ti);
        if (it == h.end()) cout << -1 << endl;
        else {
            cout << *it << endl;
            h.erase(it);
        }
    }
    return 0;   
}