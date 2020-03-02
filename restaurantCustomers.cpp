#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<int> start, end;
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        start.push_back(a);
        end.push_back(b);
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int i = 0, j = 0, k = 0, ans = 0;
    while (i < n && j < n) {
        if (start[i] < end[j]) {
            ++k;
            ans = max(ans, k);
            ++i;
        } else {
            k--;
            ++j;
        }
    }
    cout << ans << endl;
    return 0;
}