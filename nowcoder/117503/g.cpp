#include <bits/stdc++.h>

using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < 13 * n + 19; i++) {
    cout << '*';
  }
  cout << '\n';

  for (int _ = 0; _ < n; _++) {
    cout << '*';
    for (int i = 0; i < 13 * n + 17; i++) {
      cout << '.';
    }
    cout << '*';
    cout << '\n';
  }

  auto pad = [&]() {
    for (int i = 0; i < n + 1; i++) {
      cout << '.';
    }
  };


  for (int i = 0; i < 2 * n + 3; i++) {
    if (i != 0 && i != 2 * n + 2) {
      cout << '*';
      pad();
      cout << '@';
      for (int j = 0; j < i - 1; j++) {
        cout << '.';
      }
      cout << '@';
      /// 
      for (int j = i; j < 2 * n + 1; j++) {
        cout << '.';
      }
      ///
      cout << '@';

      pad();
      // F
      if (i == 0 || i == n + 1) {
        for (int j = 0; j < 2 * n + 3; j++) {
          cout << '@';
        }
      } else {
        cout << '@';
        for (int j = 0; j < 2 * n + 2; j++) {
          cout << '.';
        }
      }
      

      pad();
      if (i != 2 * n + 2) {
        cout << '@';
        for (int j = 0; j < 2 * n + 2; j++) {
          cout << '.';
        }
      } else {
        for (int j = 0; j < 2 * n + 3; j++) {
          cout << '@';
        }
      }
      

      pad();
      if (i == 0 || i == n + 1 || i == 2 * n + 2) {
        for (int j = 0; j < 2 * n + 3; j++) {
          cout << '@';
        }
      } else if (i < n + 1) {
        cout << '@';
        for (int j = 0; j < 2 * n + 2; j++) {
          cout << '.';
        }
      } else {
        for (int j = 0; j < 2 * n + 2; j++) {
          cout << '.';
        }
        cout << '@';
      }
      

      pad();

      cout << "*\n";
    } else {
      if (i == 0) {
        cout << '*';
        pad();
        cout << '@';
        for (int j = 0; j < 2 * n + 1; j++) {
          cout << '.';
        } 
        cout << '@';
        pad();
        for (int j = 0; j < 2 * n + 3; j++) {
          cout << '@';
        }
        pad();
        cout << '@';
        for (int j = 0; j < 2 * n + 2; j++) {
          cout << ".";
        }
        pad();
        for (int j = 0; j < 2 * n + 3; j++) {
          cout << '@';
        }
        pad();
        cout << "*\n";
      } else {
        cout << '*';
        pad();
        cout << '@';
        for (int j = 0; j < 2 * n + 1; j++) {
          cout << '.';
        } 
        cout << '@';
        pad();
        cout << '@';
        for (int j = 0; j < 2 * n + 2; j++) {
          cout << '.';
        }
        pad();
        for (int j = 0; j < 2 * n + 3; j++) {
          cout << "@";
        }
        pad();
        for (int j = 0; j < 2 * n + 3; j++) {
          cout << '@';
        }
        pad();
        cout << "*\n";
      }
    }
  }


  for (int _ = 0; _ < n; _++) {
    cout << '*';
    for (int i = 0; i < 13 * n + 17; i++) {
      cout << '.';
    }
    cout << '*';
    cout << '\n';
  }

  for (int i = 0; i < 13 * n + 19; i++) {
    cout << '*';
  }
  cout << '\n';

  return 0;
}