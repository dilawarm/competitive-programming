#include <bits/stdc++.h>
#include <gcd.h>
using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}