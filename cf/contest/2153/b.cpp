#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int tt;
  std::cin >> tt;
  while (tt--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    auto work = [](int a, int b, int c) -> bool {
      bool ok = true;
      while (a != 0 || b != 0 || c != 0) {
        if ((a & 1) && (b & 1) && !(c & 1)) {
          ok = false;
          break;
        }
        if ((a & 1) && !(b & 1) && (c & 1)) {
          ok = false;
          break;
        }
        if (!(a & 1) && (b & 1) && (c & 1)) {
          ok = false;
          break;
        }
        a >>= 1, b >>= 1, c >>= 1;
      }
      return ok;
    };
    if (work(a, b, c) || work(a, c, b) || work(b, c, a)) {
      std::cout << "YES\n";
    } else {
      std::cout << "NO\n";
    }
  } 
  return 0;
}