/**
 *    author:  Yuyuan
 *    created: 2026-04-01 17:45:11
**/
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
		cout << 1 << ' ';
		for (int i = n; i >= 2; i--) {
			cout << i << ' ';
		}
		cout << '\n';
	}

  return 0;
}
