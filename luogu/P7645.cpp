#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
 	int n, m;
 	std::cin >> n >> m;
 	std::vector<std::string> s(n);
 	for (int i = 0; i < n; i++) {
 		std::cin >> s[i];
 	} 
 	std::vector<std::vector<int>> vis(n, std::vector<int> (m, 0));
 	for (int i = 0; i < n; i++) {
 		for (int j = 0; j < m; j++) {
 			if (s[i][j] == 'X') {
 				int cnt = 0;
 				if (i > 0 && s[i - 1][j] == 'X') {
 					cnt++;
 				}
 				if (i < n - 1 && s[i + 1][j] == 'X') {
 					cnt++;
 				}
 				if (j > 0 && s[i][j - 1] == 'X') {
 					cnt++;
 				}
 				if (j < m - 1 && s[i][j + 1] == 'X') {
 					cnt++;
 				}
 				cnt = 4 - cnt;
 				if (cnt >= 3) {
 					vis[i][j] = 1;
 				}
 			}
 		}
 	}
 	for (int i = 0; i < n; i++) {
 		for (int j = 0; j < m; j++) {
 			if (vis[i][j] == 1) {
 				s[i][j] = '.';
 			}
 		}
 	}
 	int up = -1, down = n, left = m, right = -1;
 	for (int i = 0; i < n; i++) {
 		for (int j = 0; j < m; j++) {
 			if (s[i][j] == 'X') {
 				up = std::max(up, i);
 				down = std::min(down, i);
 				left = std::min(left, j);
 				right = std::max(right, j);
 			}
 		}
 	}
 	if (up == -1) {
 		std::cout << "";
 	} else {
 		for (int i = down; i <= up; i++) {
 			for (int j = left; j <= right; j++) {
 				std::cout << s[i][j] << "";
 			}
 			std::cout << '\n';
 		}
 	}
  return 0;
}