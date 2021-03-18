#include <bits/stdc++.h>
using namespace std;

int main()
{
    {
        // O(n) memory, O(n log log n) time.
        int n;
        vector<char> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i <= n; i++)
        {
            if (is_prime[i] && (long long)i * i <= n)
            {
                for (int j = i * i; j <= n; j += i)
                    is_prime[j] = false;
            }
        }
    }

    {
        // Fewer number of operations.
        int n;
        vector<char> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= n; i++)
        {
            if (is_prime[i])
            {
                for (int j = i * i; j <= n; j += i)
                    is_prime[j] = false;
            }
        }
    }
}