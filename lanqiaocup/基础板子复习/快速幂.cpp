#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e6 + 10;

int fastpow(int a,int b,int p){
    int res = 1;
    while(b){
        if(b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res % p;
}

void solve(){
    int m; cin>>m;
    while(m--){
        int a,b,p; cin>>a>>b>>p;
        cout << fastpow(a, b, p) << "\n";
    }
}

signed main(){
    IOS;
    solve();
    return 0;
}
