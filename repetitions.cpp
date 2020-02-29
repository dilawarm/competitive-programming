#include<bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int ans = 0;
    int i = 0;
    int streak = 1;
    while (i < s.size()) {
        if (s[i] == s[i+1]) {
            ++i;
            ++streak;
        } else {
            streak = 1;
            ++i;
        }
        if (streak > ans) ans = streak;
    }
    cout << ans << endl;
    return 0;
}