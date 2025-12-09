#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> m >> n;
    assert(m <= n);
    std::vector<int> cnt(10);
    for (int i = m; i <= n; i++) {
    	int x = i;
    	while (x) {
    		cnt[x % 10]++;
    		x /= 10;
    	}
    }
    for (int i = 0; i <= 9; i++) {
    	std::cout << cnt[i] << " \n"[i == 9];
    }
    return 0;	
}
