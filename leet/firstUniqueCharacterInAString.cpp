#include<bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
    int n = s.size();
    map<char, int> seen;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ++seen[s[i]];
        if (seen[s[ans]] > 1) ++ans; 
    }
    if (seen[s[ans]] == 1) return ans;
    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string s = "loveleetcode";
    cout << firstUniqChar(s) << endl;
    return 0;
}