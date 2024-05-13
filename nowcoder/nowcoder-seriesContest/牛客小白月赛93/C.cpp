#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e6 + 10, mod = 998244353;

int fastpow(int a,int b){
    int res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

int f(int x){
    return (x % mod + mod) % mod;
}

void solve(){
    int m,a,b,c; cin>>m>>a>>b>>c;
    int pa = f(m * (m - 1) * (m - 2) % mod + mod);
    int pc = f(m);
    int pb = f(m * m * m - pa - pc);
    int ans = (pa * a % mod + pb * b % mod + pc * c % mod) % mod * fastpow(m*m*m%mod, mod-2) % mod;
    cout << f(ans) << "\n";
}

signed main(){
    IOS;
    int t; cin>>t;
    while(t--)
        solve();
    return 0;
}
