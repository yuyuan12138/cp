/**
 * @author: yuyuan567
 * @date: 2025-07-25 14:09:45
 */

#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../algo/debug.h"
#else
#define debug(...) 42
#endif

#define all(x) (x).begin(), (x).end()

using ll = long long;

inline void speedup() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void solve(){
    int n; cin >> n;
    int x;
    if(n == 3){
        cout << "! 1 2 3" << endl;
        cout.flush();
        cin >> x;
        return ;
    }
    for(int i = 1; i <= n - 2; i++){
        for(int j = i + 1; j <= n - 1; j++){
            for(int k = j + 1; k <= n; k++){
                cout << "? " << i << " " << j << " " << k << endl;
                cout.flush();
                cin >> x;
                if(x == 0){
                    cout << "! " << i << " " << j << " " << k << endl;
                    cout.flush();
                    cin >> x;
                    
                    return ;
                }
            }
        }
    }
    return ;
}

int main() {
    speedup();
    mt19937 mt(727);
    uniform_int_distribution uni(1,3);
    int tc;cin>>tc;
    while(tc--)
    {
        int n;cin>>n;
        if(n<0)return 0;
        vector<int>vec(n);
        for(int i=0;i<n;i++)vec[i]=i+1;
        shuffle(begin(vec),end(vec),mt);
        int ii=vec[0],jj=vec[1],kk=vec[2];
        cerr<<n<<endl;
        while(1)
        {
            cout<<"? "<<ii<<" "<<jj<<" "<<kk<<endl;
            int id;cin>>id;
            if(id<0)return 0;
            if(id==0)break;
            int sw=uni(mt);
            if(sw==1)ii=id;
            else if(sw==2)jj=id;
            else kk=id;
        }
        cout<<"! "<<ii<<" "<<jj<<" "<<kk<<endl;
    }
    return 0;
}