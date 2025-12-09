#include <string.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <deque>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;
using data = int;

#define ll long long
#define all(x) (x).begin(), (x).end()

inline void speedup() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}

void solve() {
  int w, b;
  cin >> w >> b;
  ll tot = w + b;
  ll l = 0, r = 1e9;
  while (l <= r) {
    ll mid = (l + r) / 2;
    if ((mid + 1) * mid / 2 > tot) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << r << "\n";
  return;
}

int main() {
  speedup();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
