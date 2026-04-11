#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> odd, even;
    for (int i = 0, x; i < n; i++) {
      cin >> x;
      if (x % 2 == 0) {
        even.push_back(x);
      } else {
        odd.push_back(x);
      }
    }
    sort(even.begin(), even.end(), greater<int>());
    sort(odd.begin(), odd.end(), greater<int>());

    vector<int64_t> pref_e(even.size() + 1), pref_o(odd.size() + 1);
    for (int i = 0; i < even.size(); i++) {
      pref_e[i + 1] = pref_e[i] + even[i];
    }
    for (int i = 0; i < odd.size(); i++) {
      pref_o[i + 1] = pref_o[i] + odd[i];
    }

    if (odd.size() == 0) {
      for (int i = 0; i < n; i++) {
        cout << 0 << " \n"[i == n - 1];
      } 
    } else if (even.size() == 0) {
      for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
          cout << 0 << ' ';
        } else {
          cout << odd.front() << ' ';
        }
      }
      cout << '\n';
    } else {
      for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
          int idx = min(i - 1, (int) even.size());
          idx -= (idx % 2 == 0);
          int rest = i - idx;
          if (rest > odd.size()) {
            cout << 0 << ' '; 
          } else {
            cout << pref_e[idx] + odd.front() << ' ';
          }
        } else {
          int idx = min(i - 1, (int) even.size());
          idx -= (idx % 2 == 1);
          if (i - idx > odd.size()) {
            cout << 0 << ' ';
          } else {
            cout << pref_e[idx] + odd.front() << ' ';
          }
        }
      }
      cout << '\n';
    }
  }

	return 0;
}