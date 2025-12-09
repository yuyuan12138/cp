#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt;
  std::cin >> tt;
  while (tt--) {
	  int n, m;
	  std::cin >> n >> m;
		int st = 0;
	  if (n % 2 == 1) {
	  	st = 1;
	  }
	  if (n == 1) {
	  	for (int i = 0; i < m; i++) {
	  		if (st == 1) {
	  			std::cout << 'x';
	  		} else {
	  			std::cout << 'o';
	  		}
	  		st ^= 1;
	  	}
	  	std::cout << '\n';
	  } else {
	  	if (n % 2 == 1) {
	  		for (int i = 0; i < m; i++) {
		  		if (st == 1) {
		  			std::cout << 'x';
		  		} else {
		  			std::cout << 'o';
		  		}
		  		st ^= 1;
		  	}
		  	std::cout << '\n';
		  	n--;
	  	}
	  	
	  	for (int i = 0; i < n; i++) {
		  	int cur = st;
		  	for (int j = 0; j < m; j += 2) {
		  		if (cur == 0) {
		  			if (j != m - 1) {
			  			std::cout << "oo";
		  			} else {
		  				std::cout << 'o';
		  			}
		  		} else {
		  			if (j != m - 1) {
			  			std::cout << "xx";
		  			} else {
		  				std::cout << 'x';
		  			}
		  		}
		  		cur ^= 1;
		  	}
		  	st ^= 1;
		  	std::cout << '\n';
		  }
	  }
	  
  }
  
  return 0;
}