#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (n < 4) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    int x = 2;
    vector<int> seq; seq.push_back(x);
    if (n % 2 == 0) {
        while (x != n) {
            x += 2;
            seq.push_back(x);
        }
        x = 1;
        seq.push_back(x);
        while (x != n-1) {
            x += 2;
            seq.push_back(x);
        } 
    } else {
        while (x != n-1) {
            x += 2;
            seq.push_back(x);
        }
        x = 1;
        seq.push_back(x);
        while (x != n) {
            x += 2;
            seq.push_back(x);
        }
    }
    for (int i = 0; i < n; ++i) cout << seq[i] << " ";
    return 0;
}