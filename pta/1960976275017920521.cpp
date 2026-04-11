#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <tuple>
#include <array>
#include <utility>
#include <functional>
#include <climits>
#include <cstring>
#include <cmath>


using ll = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> S(n), D(n), F(n);
    for (int i = 0; i < n; i++) {
        std::cin >> S[i];
    } 
    for (int i = 0; i < n; i++) {
        std::cin >> D[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> F[i];
    }
    int max = 0;
    std::string res;
        
    std::vector<int> p(n);
    std::iota(p.begin(),p.end(),0);
    
    do { 
        int score = 0;
        int time = 0;
        std::string t = "";
        for (int i : p) {
            time += D[i];
            t += i + 'A';
            score += std::max(S[i] - 50 * F[i] - time * S[i] / 250, S[i] * 3 / 10);
        }
        if (score >= max) {
            max = score;
            res = t;
        }
    } while(next_permutation(p.begin(),p.end()));
    std::cout << max << ' ' << res << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    

    return 0;
}