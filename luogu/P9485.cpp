#include <bits/stdc++.h>

using i64 = long long;

template<class T,
  class Cmp = std::less<T>>
struct RMQ {
  const Cmp cmp = Cmp();
  static constexpr uint32_t B = 64;
  int n;
  std::vector<std::vector<T>> a;
  std::vector<T> pre, suf, ini;
  std::vector<uint64_t> stk;
  RMQ() {}
  RMQ(const std::vector<T> &v) {
    init(v);
  }
  void init(const std::vector<T> &v) {
    n = v.size();
    pre = suf = ini = v;
    stk.resize(n);
    if (!n) {
      return;
    }
    const int M = (n - 1) / B + 1;
    const int lg = std::__lg(M);
    a.assign(lg + 1, std::vector<T>(M));
    for (int i = 0; i < M; i++) {
      a[0][i] = v[i * B];
      for (int j = 1; j < B && i * B + j < n; j++) {
        a[0][i] = std::min(a[0][i], v[i * B + j], cmp);
      }
    }
    for (int i = 1; i < n; i++) {
      if (i % B) {
        pre[i] = std::min(pre[i], pre[i - 1], cmp);
      }
    }
    for (int i = n - 2; i >= 0; i--) {
      if (i % B != B - 1) {
        suf[i] = std::min(suf[i], suf[i + 1], cmp);
      }
    }
    for (int j = 0; j < lg; j++) {
      for (int i = 0; i + (2 << j) <= M; i++) {
        a[j + 1][i] = std::min(a[j][i], a[j][i + (1 << j)], cmp);
      }
    }
    for (int i = 0; i < M; i++) {
      const int l = i * B;
      const int r = std::min(uint32_t(n), l + B);
      uint64_t s = 0;
      for (int j = l; j < r; j++) {
        while (s && cmp(v[j], v[std::__lg(s) + l])) {
          s ^= uint64_t(1) << std::__lg(s);
        }
        s |= uint64_t(1) << (j - l);
        stk[j] = s;
      }
    }
  } 
  T operator()(int l, int r) {
    if (l / B != (r - 1) / B) {
      T ans = std::min(suf[l], pre[r - 1], cmp);
      l = l / B + 1;
      r = r / B;
      if (l < r) {
        int k = std::__lg(r - l);
        ans = std::min({ans, a[k][l], a[k][r - (1 << k)]}, cmp);
      }
      return ans;
    } else {
      int x = B * (l / B);
      return ini[__builtin_ctzll(stk[r - 1] >> (l - x)) + l];
    }
  }
};

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	if (n <= 3) {
		std::cout << 0 << '\n';
		return ;
	}
	auto work = [](std::vector<int>& a) -> int {
		RMQ<int, std::greater<int>> rmq(a);
		int ans = 0;
		for (int i = 1; i < a.size() - 1; i++) {
			ans += std::max(0, std::min(rmq(0, i), rmq(i + 1, (int)a.size())) - a[i]);
		}
		return ans;
	};
	std::vector<int> b = a;
	for (int i = 1; i < n; i++) {
		if (b[i] < b[i - 1]) {
			b[i - 1] = b[i];
			break;
		}
	}
	int ans1 = work(b);
	b = a;
	for (int i = n - 2; i >= 0; i--) {
		if (b[i] < b[i + 1]) {
			b[i + 1] = b[i]; 
			break;
		}
	}
	int ans2 = work(b);
	int ans = std::min(ans1, ans2);
	int tot = work(a);
	RMQ<int, std::greater<int>> rmq(a);
	for (int i = 1; i < n - 1; i++) {
		int t = std::max(0, std::min(rmq(0, i), rmq(i + 1, n)) - a[i]);
		ans = std::min(ans, tot - t);
	}	
	std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
    	solve();
    }
    return 0;
}