#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    set<int> candidate;
    candidate.insert(b);
    candidate.insert(a - b);
    if (candidate.size() == 1) {
      int val = *candidate.begin();
      if (c == x || val - c == x) {
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    } else {
      if (c == x) {
        cout << "Yes\n";
      } else {
        vector<int> vals(candidate.begin(), candidate.end());
        int val1 = vals[0], val2 = vals[1];
        
        if ((c - x) % (val1 - val2) == 0 || (c - x) % (val2 - val1) == 0) {
          cout << "Yes\n";
        } else if ((c + x - val1) % (val1 - val2) == 0) {
          cout << "Yes\n";
        } else if ((c + x - val2) % (val2 - val1) == 0) {
          cout << "Yes\n";
        } else {
          cout << "No\n";
        }
      
      }
    }
  }

  return 0;
}