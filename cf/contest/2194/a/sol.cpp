#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <utility>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
	
	int tt;
	cin >> tt;
	while (tt--) {
		int n, w;
		cin >> n >> w;
		cout << n - n / w << '\n';
	}

  return 0;
}

