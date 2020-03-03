#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<pair<int, int>> times;
	int a, b;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		times.push_back({a, b});
	}
	sort(times.begin(), times.end(), [](pair<int, int> &x, pair<int, int> &y) -> bool {
		return x.second < y.second;		
	});

	int end = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		int a = times[i].first, b = times[i].second;
		if (a >= end) {
			end = b;
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
