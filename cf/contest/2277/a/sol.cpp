#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector<int> freq(n + 1);
		for (int i = 0, x; i < n; i++) {
			cin >> x;
			freq[x]++;
		}
		int mex = 0;
		int last = 0;
		while (last + freq[mex] >= k && freq[mex] > 0) {
			last = last + freq[mex] - k;
			mex++; 
		}
		cout << mex << '\n';
	}
	return 0;
}
