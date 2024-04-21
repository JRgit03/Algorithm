#include <bits/stdc++.h>
#define int long long
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

const int mod = 1e9 + 7;
int fastpow(int a,int b){
    int res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    int ans = 0;
    for(int i=0;i<n;i++){
        int x = s[i] - '0';
        if((x + 1) & 1) ans = (ans + fastpow(2, i)) % mod;
    } 
    int suf = 0;
    for(int i=n-1;i>=0;i--){
        int x = s[i] - '0';
        if((x + 1) & 1) {
            if(x == 0) ans = (ans - suf + mod) % mod;
            suf = (suf * 2 + 1) % mod;
        }else{
            suf = suf * 2 % mod;
        }
    }
    ans = (ans % mod + mod) % mod;
    cout << ans << "\n";
}

signed main(){
    solve();
    return 0;
}