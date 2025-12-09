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

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n - 2; i++) {
        if (k % 2 == 0) {
            cout << n - 1 << " ";
        } else {
            cout << n << " ";
        }
    }
    cout << n << " " << n - 1 << "\n";

    return;
}

int main() {
    speedup();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
