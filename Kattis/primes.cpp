#include<bits/stdc++.h>
using namespace std;

void peculiar(int l, int r, int X, int Y, vector<int> primes, vector<int> &answers) {
    if (X == 1) answers.push_back(r);
    for (int i = l; i < primes.size(); ++i) {
        if (Y >= primes[i]) peculiar(i, r*primes[i], (X-1)/primes[i]+1, Y/primes[i], primes, answers);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    while (1) {
        int n; cin >> n;
        if (!n) return 0;

        vector<int> primes(n, 0);
        for (int i = 0; i < n; ++i) cin >> primes[i];
        
        int X, Y; cin >> X >> Y;
        vector<int> answers;
        peculiar(0, 1, X, Y, primes, answers);
        
        sort(answers.begin(), answers.end());
        if (!answers.size()) cout << "none" << endl;
        else {
            for (int i = 0; i < answers.size()-1; ++i) cout << answers[i] << ",";
            cout << answers[answers.size()-1] << endl;
        }
    }
    return 0;
}