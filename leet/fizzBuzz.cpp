#include<bits/stdc++.h>
using namespace std;

vector<string> fizzBuzz(int n) {
    vector<string> v;
    for (int i = 1; i <= n; ++i) {
        if (i % 3 == 0 && i % 5 == 0) v.push_back("FizzBuzz");
        else if (i % 3 == 0) v.push_back("Fizz");
        else if (i % 5 == 0) v.push_back("Buzz");
        else v.push_back(to_string(i));
    }
    return v;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n = 15;
    vector<string> v = fizzBuzz(n);
    for (int i = 0; i < v.size(); ++i) cout << v[i] << " ";
}