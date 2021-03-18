#include <bits/stdc++.h>
#include <gcd.h>
using namespace std;

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}