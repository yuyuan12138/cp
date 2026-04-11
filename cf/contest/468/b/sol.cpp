#include <bits/stdc++.h>
struct TwoSat {
  int n;
  std::vector<std::vector<int>> e;
  std::vector<bool> ans;
  TwoSat(int n) : n(n), e(2 * n), ans(n) {}
  void addClause(int u, bool f, int v, bool g) {
    e[2 * u + !f].push_back(2 * v + g);
    e[2 * v + !g].push_back(2 * u + f);
  }
  bool satisfiable() {
    std::vector<int> id(2 * n, -1), dfn(2 * n, -1), low(2 * n, -1);
    std::vector<int> stk;
    int now = 0, cnt = 0;
    std::function<void(int)> tarjan = [&](int u) {
      stk.push_back(u);
      dfn[u] = low[u] = now++;
      for (auto v : e[u]) {
        if (dfn[v] == -1) {
          tarjan(v);
          low[u] = std::min(low[u], low[v]);
        } else if (id[v] == -1) {
          low[u] = std::min(low[u], dfn[v]);
        }
      }
      if (dfn[u] == low[u]) {
        int v;
        do {
          v = stk.back();
          stk.pop_back();
          id[v] = cnt;
        } while (v != u);
        ++cnt;
      }
    };
    for (int i = 0; i < 2 * n; ++i)
      if (dfn[i] == -1) tarjan(i);
    for (int i = 0; i < n; ++i) {
      if (id[2 * i] == id[2 * i + 1]) return false;
      ans[i] = id[2 * i] > id[2 * i + 1];
    }
    return true;
  }
  std::vector<bool> answer() { return ans; }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, a, b;
  std::cin >> n >> a >> b;
  std::vector<int> c(n);
  std::set<int> st;
  std::map<int, int> mp;
  for (int i = 0; i < n; i++) {
    std::cin >> c[i];
    st.insert(c[i]);
    mp[c[i]] = i;
  }
  TwoSat twosat(n);
  for (int i = 0; i < n; i++) {
    if (st.contains(a - c[i])) {
      twosat.addClause(i, true, mp[a - c[i]], false);
    } else {
      twosat.addClause(i, true, i, true);
    }
    if (st.contains(b - c[i])) {
      twosat.addClause(i, false, mp[b - c[i]], true);
    } else {
      twosat.addClause(i, false, i, false);
    }
  }
  bool ok = twosat.satisfiable();
  if (ok) {
    std::cout << "YES\n";
    std::vector<bool> ans = twosat.answer();
    for (int i = 0; i < ans.size(); i++) {
      std::cout << ans[i] << " \n"[i == ans.size() - 1];
    }
  } else {
    std::cout << "NO\n";
  }

  return 0;
}
