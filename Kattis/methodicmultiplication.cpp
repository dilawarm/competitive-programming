#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string f;
    cin >> f;
    string s;
    cin >> s;

    size_t total_s = count(f.begin(), f.end(), 'S') * count(s.begin(), s.end(), 'S');

    for (int i = 0; i < total_s; ++i)
    {
        cout << "S(";
    }

    cout << "0";

    for (int i = 0; i < total_s; ++i)
    {
        cout << ")";
    }

    return 0;
}