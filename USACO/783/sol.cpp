#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <utility>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

	vector x(2, vector<int>(4));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			int t;
			cin >> t;
			x[i][j] = t + 1000;
		}
	}
	vector<vector<int>> s(2005, vector<int> (2005));
	for (int i = x[0][0]; i <= x[0][2]; i++) {
		for (int j = x[0][1]; j <= x[0][3]; j++) {
			s[i][j] = 1;
		}
	}
	for (int i = x[1][0]; i <= x[1][2]; i++) {
		for (int j = x[1][1]; j <= x[1][3]; j++) {
			s[i][j] = 2;
		}
	}

	int mxx = 0, mxy = 0, mnx = 1e9, mny = 1e9;
	bool found = false;
	for (int i = 0; i < 2004; i++) {
		for (int j = 0; j < 2004; j++) {
			if (s[i][j] == 1) {
				found = true;
				mxx = max(mxx, i);
				mxy = max(mxy, j);
				mnx = min(mnx, i);
				mny = min(mny, j);
			}
		}
	}
	if (found)
		cout << (mxx - mnx) * (mxy - mny);
	else
		cout << 0;

  return 0;
}

