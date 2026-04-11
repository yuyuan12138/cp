#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> get_divisors(const int n) {
	vector<vector<int>> divs(n + 1);
  for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
      divs[j].push_back(i);
    }
  }
	return divs;
}

constexpr int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	auto divs = get_divisors(3e5 + 1);
	int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
		vector<int> dp(n + 1, inf);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
			dp[a[i]] = 1;
    }
		for (int x = 2; x <= n; x++) {
			for (int div : divs[x]) {
				dp[x] = min(dp[x], dp[div] + dp[x / div]);
			}
		}
		for (int x = 1; x <= n; x++) {
			cout << (dp[x] == inf ? -1 : dp[x]) << " \n"[x == n];
		}
  }
	
	return 0;
}