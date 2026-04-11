#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
void discretization(std::vector<T>& a) {
    const int n = a.size();
	std::vector<T> tmp(a);  
	std::sort(tmp.begin(), tmp.end());
	tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());
	for (int i = 0; i < n; i++) {
	a[i] = std::lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin();
	}
}

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};


int main() { 
	std::ios::sync_with_stdio(false); 
	std::cin.tie(nullptr); 
	int n; 
	std::cin >> n; 
	std::vector<std::array<int, 2>> s(n); 
	for (int i = 0; i < n; i++) { 
		std::cin >> s[i][0]; 
	} 
	for (int i = 0; i < n; i++) {
		std::cin >> s[i][1];
	}
	std::sort(s.begin(), s.end()); 
	i64 ans = 0;
	std::vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		a[i] = s[i][0];
		b[i] = s[i][1];
	}	
	discretization(a);
	discretization(b);
	std::map<int, std::vector<int>> mp;
	Fenwick<i64> fw(n);
	for (int i = 0; i < n; i++) {
		mp[a[i]].push_back(b[i]);
	}
	for (auto& [x, vec] : mp) {
		std::map<int, int> tmp;
		for (int v : vec) {
			tmp[v]++;
			ans += fw.rangeSum(v, n);
		}
		for (int v : vec) {
			fw.add(v, 1);
		}
		ans += 1ll * vec.size() + (vec.size() - 1) * vec.size() / 2;
		for (auto& [val, c] : tmp) {
			ans += 1ll * (c - 1) * c / 2;
		}

	}
	std::cout << ans;
	return 0;
}