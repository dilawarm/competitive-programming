#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<bool> a(15, false);
    vector<bool> b(15, false);
    vector<bool> c(15, false);
    vector<bool> d(15, false);

    int q = 0;
    char pos;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> pos;
            if (pos == '*') {
                ++q;
                
                if (a[j-i+7] || b[i+j] || c[i] || d[j]) {
                    cout << "invalid";
                    return 0; 
                }

                a[j-i+7] = true;
                b[i+j] = true;
                c[i] = true;
                d[j] = true;
            }
        }
    }
    if (q == 8) cout << "valid";
    else cout << "invalid";

    return 0;
}