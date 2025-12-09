#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
 	int tt;
 	std::cin >> tt;
 	while (tt--) {
 		int64_t n;
 		std::cin >> n;
 		int ans = 0;
 		while (n) {
 			if ((n & 1ll) == 0) {
 				n >>= 1ll;
 			} else {
	 			if (((n >> 1ll) & 1ll)) {
	 				n += 1;
	 			} 
	 			ans++;
	 			n >>= 1ll;
 			}
 		}
 		std::cout << ans << '\n';
 	} 
  return 0;
}