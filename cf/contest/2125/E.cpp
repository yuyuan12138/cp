#include <bits/stdc++.h>
using namespace std;
static const int MOD = 998244353;

int add(int a,int b){
    a+=b;
    if(a>=MOD) a-=MOD;
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long n, x;
        cin >> n >> x;

        // 1) If n == 1, any single problem from [1..x] works:
        if (n == 1) {
            cout << (x % MOD) << "\n";
            continue;
        }
        // 2) If n > x, can't pick n distinct from [1..x]:
        if (n > x) {
            cout << 0 << "\n";
            continue;
        }
        // 3) Compute threshold so that the smallest possible sum
        //    n(n+1)/2 exceeds x+1 ⇒ no valid k <= x+1 at all.
        long long lhs = (long long)n * (n+1) / 2;
        if (lhs > x + 1) {
            cout << 0 << "\n";
            continue;
        }
        // Now we do the DP to count partitions of s into n distinct parts,
        // for s = n(n+1)/2 ... x+1, and sum them.

        int K = (int)(x + 1);
        vector<int> dp_prev(K+1, 0), dp_curr(K+1, 0), prefix(K+1, 0);
        dp_prev[0] = 1;  // one way to make sum=0 with zero parts

        // Build up to exactly n parts.
        for (int i = 1; i <= n; i++) {
            // clear dp_curr
            fill(dp_curr.begin(), dp_curr.end(), 0);
            // recurrence: dp[i][s] = dp[i][s-i] (use a new part of size i)
            //                   + dp[i-1][s-i] (use exactly i-1 parts to make s-i
            //                                    then add part 'i')
            for (int s = i; s <= K; s++) {
                dp_curr[s] = add(
                    dp_curr[s - i],
                    dp_prev[s - i]
                );
            }
            // swap in for next iteration
            dp_prev.swap(dp_curr);
        }
        // prefix sums of dp_prev[s] over s=0..K
        prefix[0] = dp_prev[0];
        for (int s = 1; s <= K; s++) {
            prefix[s] = add(prefix[s-1], dp_prev[s]);
        }
        // answer is sum_{s = n(n+1)/2 .. x+1} dp[n][s]
        int start = (int)lhs;  // minimal s = n(n+1)/2
        int ans = prefix[K];
        if (start > 0) {
            ans = (ans - prefix[start - 1] + MOD) % MOD;
        }
        cout << ans << "\n";
    }
    return 0;
}