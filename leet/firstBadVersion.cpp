#include<bits/stdc++.h>
using namespace std;

int firstBadVersion(int n) {
    int l = 1, r = n;
    while (l <= r) {
        int m = l + (r-l) / 2;
        if (isBadVersion(m) && !isBadVersion(m-1)) return m;
        if (isBadVersion(m)) r = m - 1;
        else l = m + 1;
    }
    return -1;
}