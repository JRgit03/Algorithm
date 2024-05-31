#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e5 + 10, mod = 1e9 + 7;
int m;
int fact[N], infact[N];

int fastpow(int a,int b){
    int res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

// C(n, m) n个物品选m个的方案数 = n! / m! / (n-m)!
int c(int n,int m){
    if(n < m) return 0;
    return fact[n] * infact[m] % mod * infact[n-m] % mod;
}

void solve(){
    fact[0] = infact[0] = 1;
    for(int i=1;i<=100000;i++){
        fact[i] = fact[i-1] * i % mod;
        infact[i] = infact[i-1] * fastpow(i, mod-2) % mod;
    }
    cin>>m;
    while(m--){
        int a,b; cin>>a>>b; debug(a, b);
        cout << c(a, b) << "\n";
    }
}

signed main(){
    IOS;
    solve();
    return 0;
}
