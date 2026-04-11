#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		a[n - 1] = 1;
    bool ok = false;
		for (int i = n - 2; i >= 0; i--) {
			if (ok) {
        a[i] = a[i + 1] - (i + 1);
			} else {
				a[i] = a[i + 1] + (i + 1);
			}
      ok ^= 1;
		}
		for (int i = 0; i < n; i++) {
			cout << a[i] << " \n"[i == n - 1];
		}
	}

	return 0;
}