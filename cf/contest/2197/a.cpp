#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

int digit_sum(int x) {
  int sum = 0;
  while (x) {
    sum += (x % 10);
    x /= 10;
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i <= 90; i++) {
      if (n + i  - digit_sum(i + n) == n) {
        cnt++;
      }
    }
    cout << cnt << '\n';
  }

  return 0;
}