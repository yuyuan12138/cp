#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string> 
#include <string.h>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <bitset>
#include <forward_list>
#include <deque>
#include <set>
#include <tuple>
#include <utility>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <chrono>
#include <random>
#include <complex>
#include <functional>
#include <cassert>
#include <climits>
#include <limits>
#include <tuple>
#include <cstdint>
#include <array>

using namespace std;
using data = int;

#define ll long long

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve() {
    int n; cin >> n;
    vector<int> nums(n);
    vector<int> freq(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (nums[i] > n) {
            continue;
        } else {
            freq[nums[i]]++;
        }
    }

    int M = 0;
    while (M <= n && freq[M] > 0) {
        M++;
    }

    vector<ll> prefix_sum(n+1, 0);
    if (n > 0) {
        prefix_sum[0] = freq[0];
        for (int i = 1; i <= n; i++) {
            prefix_sum[i] = prefix_sum[i-1] + freq[i];
        }
    } else {
        prefix_sum[0] = freq[0];
    }

    vector<int> ans(n+2, 0); 
    for (int i = 0; i <= min(M, n); i++) {
        ll r_min = freq[i];  

        ll add = 0;
        if (i-1 >= 0) {
            add += (prefix_sum[i-1] - i);
        }
        add += (n - prefix_sum[i]);
        ll L = r_min;
        ll R = r_min + add;
        if (L <= n) {
            ans[L]++;
            if (R+1 <= n+1) {
                ans[R+1]--;
            }
        }
    }
    int cur = 0;
    for (int k = 0; k <= n; k++) {
        cur += ans[k];
        cout << cur << " ";
    }
    cout << "\n";
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}