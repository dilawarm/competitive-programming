#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> a, b;
	int x, y, ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		a.push_back(x);	
	}
	for (int i = 0; i < m; ++i) {
		cin >> y;
		b.push_back(y);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (b[j] > a[i]+k) ++i;
		else if (b[j] < a[i] - k) ++j;
		else {
			++i;
			++j;
			++ans;
		}  
	}
	cout << ans << endl;
}
