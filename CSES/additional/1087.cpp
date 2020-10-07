/*
You are given a DNA sequence consisting of characters A, C, G, and T.

Your task is to find the shortest DNA sequence that is not a subsequence of the original sequence.
*/

#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string input; cin >> input;
    string output = "";

    set<char> counter;
    for (size_t i = 0; i < input.size(); ++i) {
        counter.insert(input[i]);
        if (counter.size() == 4) {
            output += input[i];
            counter.clear();
        }
    }
    for (auto &c : "AGCT") {
        if (!counter.count(c)) {
            output += c;
            break;
        }
    }
    cout << output << "\n";
    return 0;
}