#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::vector<std::string> s = {"12", "123", "1234"};
  std::vector<std::vector<std::string>> per(3);
  for (int i = 0; i < 3; i++) {
    do {
      per[i].push_back(s[i]);
    } while (std::next_permutation(s[i].begin(), s[i].end()));
  }
  int tt;
  std::cin >> tt;
  while (tt--) {
    std::string t;
    int a, b;
    int idx;
    std::cin >> t >> a >> b;
    if (t == "12") {
      idx = 0;
    } else if (t == "123") {
      idx = 1;
    } else {
      idx = 2;
    }
    std::string sa = per[idx][a - 1], sb = per[idx][b - 1];
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < t.size(); i++) {
      if (sa[i] == sb[i]) {
        cnt1++;
      } else {
        cnt2++;
      }
    }
    std::cout << cnt1 << "A" << cnt2 << "B" << '\n';
  }
  return 0;
}
