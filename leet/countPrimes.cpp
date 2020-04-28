#include<bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
    vector<bool> sieve(n+1, true);
    for (int i = 2; i*i <= n; ++i) {
        if (sieve[i]) {
            for (int j = i*i; j <= n; j += i) sieve[j] = false;
        }
    }
    return count(sieve.begin()+2, sieve.end(), true);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n = 19;
    cout << countPrimes(n) << endl;
    return 0;
}