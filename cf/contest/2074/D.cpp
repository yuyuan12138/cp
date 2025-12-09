/**
 * @author: yuyuan567
 * @date: 2025-07-25 14:28:00
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
    int n, m;
    cin >> n >> m;
    map<ll, ll> cnt;
    auto isqrt=[&](ll x)
    {
        ll val=sqrtl(x)+5;
        while(val*val>x)val--;
        return val;
    };
    vector<ll> a(n), r(n);
    for(ll&i:a)cin>>i;
    for(ll&i:r)cin>>i;
    for(int i=0;i<n;i++)
    {
        ll aa=a[i],rr=r[i];
        for(ll x=aa-rr;x<=aa+rr;x++)
        {
            cnt[x]=max(cnt[x],2*isqrt(rr*rr-(x-aa)*(x-aa))+1);
        }
    }
    ll ans=0;
    for(auto[x,c]:cnt)ans+=c;
    cout<<ans<<"\n";
    return ;
}

int main() {
    speedup();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}