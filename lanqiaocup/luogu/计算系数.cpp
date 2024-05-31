#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e3 + 10, mod = 1e4 + 7;
int a,b,k,n,m;
int c[N][N]; // c(n,m) n个物品选m个的组合数

int fastpow(int a,int b,int mod){
    int res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

// a^n * b*m * c(k, n)
void solve(){
    cin>>a>>b>>k>>n>>m;
    for(int i=0;i<=k;i++){
        for(int j=0;j<=i;j++){
            if(!j) c[i][j] = 1;
            else c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
        }
    }    
    int ans = fastpow(a, n, mod) * fastpow(b, m, mod) % mod * c[k][n] % mod;
    cout << (ans % mod + mod) % mod << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
