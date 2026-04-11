#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt;
  std::cin >> tt;
  while (tt--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> pos(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      pos[--a[i]] = i;
    }
    int max = *std::max_element(a.begin(), a.end());
    int min = *std::min_element(a.begin(), a.end());
    std::string s;
    std::cin >> s;
    std::string t(n, '0');
    for (int i = 1; i < pos[max]; i++) {
      if (a[i] > a[0] && a[i] < max) {
        t[i] = '1';
      }
    }
    for (int i = 1; i < pos[min]; i++) {
      if (a[i] < a[0] && a[i] > min) {
        t[i] = '1';
      }
    }
    for (int i = n - 2; i > pos[max]; i--) {
      if (a[i] > a[n - 1] && a[i] < max) {
        t[i] = '1';
      }
    } 
    for (int i = n - 2; i > pos[min]; i--) {
      if (a[i] < a[n - 1] && a[i] > min) {
        t[i] = '1';
      }
    }
    int l = pos[min], r = pos[max];
    if (l > r) {
      std::swap(l, r);
    }
    for (int i = l + 1; i < r; i++) {
      if (a[i] > min && a[i] < max) {
        t[i] = '1';
      }
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1' && t[i] != '1') {
        ok = false;
      }
    } 
    std::cerr << "s: " << s << '\n' << "t: " << t << '\n'; 
    if (!ok) {
      std::cout << -1 << '\n';
    } else {
      std::cout << 5 << '\n';
      std::cout << "1 " << pos[max] + 1 << '\n';
      std::cout << "1 " << pos[min] + 1 << '\n';
      std::cout << pos[max] + 1 << " " << n << '\n';
      std::cout << pos[min] + 1 << " " << n << '\n';
      std::cout << l + 1 << ' ' << r + 1 << '\n';
    }
  }

  return 0;
}

