#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

const int MOD  = 1000000007;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s; cin >> s;

    ll question = 0, zero = 0, one = 0, prev = 1, power = 1, ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '?') {
            ans =  (ans * 2 % MOD) + (one * power % MOD);
            ans %= MOD;
            ans += (question*(prev)) % MOD;
            question += 1;
            prev = power;
            power *= 2;
            power %= MOD;
        }
        else if (s[i] == '1') one += 1;
        else if (s[i] == '0') {
            if (question > 0) {
                ans += (one * power % MOD) + (prev * question % MOD);
                ans %= MOD;
            }
            else {
                ans += one;
                ans %= MOD;
            }
            zero += 1;
        }
    }

    cout << ans % MOD << endl;

    return 0;
}