#include <bits/stdc++.h>

constexpr int inf = 1e9;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int k, v, n;
  std::cin >> k >> v >> n;
  std::vector<int> size(n), value(n);
  for (int i = 0; i < n; i++) {
  	std::cin >> size[i] >> value[i];
  }
  std::vector<std::vector<int>> f(v + 1, std::vector<int> (k, -inf));
  f[0][0] = 0;
  for (int i = 0; i < n; i++) {
  	for (int j = v; j >= size[i]; j--) {
  		int cur1 = 0, cur2 = 0;
  		std::vector<int> nf = f[j];
  		for (int cnt = 0; cnt < k; cnt++) {
  			if (f[j][cur1] > f[j - size[i]][cur2] + value[i]) {
  				nf[cnt] = f[j][cur1];
  				cur1++;
  			} else {
  				nf[cnt] = f[j - size[i]][cur2] + value[i];
  				cur2++;
  			}
  		}
  		f[j] = nf;
  	}
  } 
  int ans = 0;
  for (int i = 0; i < k; i++) {
  	ans += f[v][i];
  }
  std::cout << ans;
  return 0;
}