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
/**
 *  Problem statement:
 *      1. n groups m classrooms
 *      2. first day 6 classes per group    
 *      3. each classroom one class and one group
 *      4. own index
 *      5. heightest floor is 1e7
 *      
 *      Find the maximum movement.
 *  
 *  由于每个Group实际上是等价的
 *  所以可以贪心的去获取最大movement
 *  6 * n
 */

void solve(){
    int n, m; cin >> n >> m;
    // 记录有多少层和每一层的教室数量
    vector<string> floors;
    for(int i = 1; i <= m; i++){
        string s; cin >> s;
        floors.push_back(s);
    }

    sort(all(floors), [](string& a, string& b){
        return stoi(a.substr(0, a.size() - 2)) < stoi(b.substr(0, b.size() - 2));
    });
    
    // for(auto& x: floors){
    //     cout << x << " ";
    // }
    // cout  << "\n";

    vector<string> st(n + 1);
    vector<string> ed(n + 1);
    for(int i = 1; i <= n; i++){
        st[i] = floors[i - 1];
        ed[i] = floors[m - i];
    }
// for(auto& x: ed){
//         cout << x << " ";
//     }
//     cout  << "\n";
    // 最大的pair可以以偶数使用
    // 如果 n 为偶数那么结束，如果n为奇数再加一行
    for(int i = 1; i <= n / 2; i++){
        for(int j = 1; j <= 3; j++){
            cout << st[i] << " " << ed[i] << " ";
        }
        cout << "\n";
        for(int j = 1; j <= 3; j++){
            cout << ed[i] << " " << st[i] << " ";
        }
        cout << "\n";
    }

    if(n % 2){
        for(int j = 1; j <= 3; j++){
            cout << st[n / 2 + 1] << " " << ed[n / 2 + 1] << " ";
        }
        cout << "\n";
    }
    

    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}