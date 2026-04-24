#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("blocks.in", "r", stdin);
  freopen("blocks.out", "w", stdout);
  int n;
  cin >> n;
  vector<int> cnt(26);
  for (int i = 0; i < n; i++) {
    string s, t;
    cin >> s >> t;
    vector<int> cnt1(26), cnt2(26);
    for (auto c : s) {
      cnt1[c - 'a']++;
    }
    for (auto c : t) {
      cnt2[c - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      cnt[i] += max(cnt1[i], cnt2[i]);
    }
  }
  for (int i = 0; i < 26; i++) {
    cout << cnt[i] << '\n';
  }
  return 0;
}
