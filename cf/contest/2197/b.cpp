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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> p(n), a(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    
    int j = 0;
    for (int i = 0; i < n; i++) {
      while (j < n && a[j] == p[i]) {
        j++;
      }
    }
     
    if (j == n) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
    
  }

  return 0;
}