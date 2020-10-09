/*
Your task is to count the number of one bits in the binary representations of integers between 1 and n.
*/
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;

    long long ans = 0;

    for (int i = 0; 1LL << i <= n + 1; ++i)
    {
        ans += n >> (i + 1) << i;
        if (n & 1LL << i)
            ans += (n & (1LL << i) - 1) + 1;
    }
    cout << ans << "\n";

    return 0;
}