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

void solve(){
    int n; cin >> n;
    vector<pii> points(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> points[i].first >> points[i].second;
    }

    vector<int> idx(n);
    for(int i = 1; i <= n; i++){
        idx[i - 1] = i;
    }

    sort(all(idx), [&](int x, int y){
        if(points[x].first == points[y].first){
            return points[x].second < points[y].second;
        }
        return points[x].first < points[y].first;
    });

    vector<int> left(idx.begin(), idx.begin() + n / 2);
    vector<int> right(idx.begin() + n / 2, idx.end());

    sort(all(left), [&](int x, int y){

        return points[x].second > points[y].second;

    });

    sort(all(right), [&](int x, int y){
        return points[x].second < points[y].second;
    });

    for(int i = 0; i < n / 2; i++){
        cout << left[i] << " " << right[i] << "\n";
    }

}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}