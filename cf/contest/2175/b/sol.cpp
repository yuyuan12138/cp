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

  int tt;
  cin >> tt;
  while (tt--) {
    int n, l, r;
    cin >> n >> l >> r;
		vector<int> b(n + 1);
		for (int i = 1; i <= n; i++) {
			b[i] = i;
		}
		b[r] = l - 1;
		for (int i = 1; i <= n; i++) {
			cout << (b[i] ^ b[i - 1]) << " \n"[i == n];
		}
  }

  return 0;
}
