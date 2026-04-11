#include <bits/stdc++.h>

using namespace std;

int count_num_of_1(vector<char>& v){
    int count = 0;
    for(int i = 0; i < v.size(); i++){
        if (v[i] == '1')
        {
            count++;
        }
        
    }
    return count;
}

void solve(){
    int n;
    cin >> n;
    vector<char> v(n);
    for(char& x: v) cin >> x;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(v[i] == '1'){
            v[i] = '0';
        }else{
            v[i] = '1';
        }
        ans += count_num_of_1(v);
        if(v[i] == '1'){
            v[i] = '0';
        }else{
            v[i] = '1';
        }
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t -- )solve();
    return 0;
}