#include <bits/stdc++.h>

using namespace std;


#define all(x) (x).begin(), (x).end()

using ll = long long;
using pii = pair<int, int>;

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool cmp(pair<int, int>& a, pair<int, int>& b){
    return a.second < b.second;
}

void solve(){
    int n, m, L; cin >> n >> m >> L;
    vector<pii> hurdles(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> hurdles[i].first >> hurdles[i].second;
    }
    vector<pii> power_ups(m + 1);
    for(int i = 1; i <= m; i++){
        cin >> power_ups[i].first >> power_ups[i].second;
    }

    priority_queue<pii, vector<pii>, decltype(&cmp)> q(cmp);

    int slow = 1;
    int cnt = 0;
    ll sum = 0;
    for(int fast = 1; fast <= n; fast++){
        while(power_ups[slow].first <= hurdles[fast].first && slow <= m){
            q.push(power_ups[slow]);
            slow++;
        }
        while(sum < hurdles[fast].second - hurdles[fast].first + 1){
            if(q.empty()){
                cout << -1 << "\n";
                return ;
            }
            sum += q.top().second; q.pop();
            cnt += 1;
        }
    }
    cout << cnt << "\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}