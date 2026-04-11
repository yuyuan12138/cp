#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int n = s.size();
  int64_t ans = 0;
  std::vector<int> mp(2019);
  mp[0] = 1;
  int cur = 0;
  int pow = 1;
  for (int i = n - 1; i >= 0; i--) {
    cur += pow * (s[i] - '0'); 
    cur %= 2019;
    mp[cur]++;
    pow = (pow * 10) % 2019;
  }
  for (int i = 0; i < 2019; i++) {
    ans += int64_t(mp[i]) * (mp[i] - 1) / 2;
  }
  std::cout << ans;
  return 0;
}
