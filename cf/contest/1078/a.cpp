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

#define ll long long

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (auto& a : nums) cin >> a;
    ll sum = accumulate(nums.begin(), nums.end(), 0LL);

    if (sum == x * n) {
        cout << "YES\n";
        return;
    }

    cout << "NO\n";

    return;
}

int main() {
    speedup();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
