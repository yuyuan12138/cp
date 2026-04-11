#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve(){
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    int last = n - m;
    int flag = 0;
    if(-l >= last){
        l += last;
        cout << l << " " << r << endl;
        return ; 
    }else{
        last -= -l;
        cout << 0 << " " << r - last << endl;
    }


}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}