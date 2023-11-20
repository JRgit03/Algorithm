#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 10, mod = 1e9;
int n,m; 
int a[maxn],p[maxn];

int fastpow(int a,int b){
    int res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

void bf(){
    int ans = 0;
    for(int i=1;i<=m;i++){
        int s = 0;
        for(int j=1;j<=n;j++){
            s += a[j] / (long long)ceil(log2(a[j]) / log2(p[i])); 
            // s += a[j] / (long long)(log2(a[j]) + log2(p[i]) / log2(p[i])); 
        }
        ans += i * s;
    }
    cout << ans << "\n";
}

void solve(){
    cin>>n>>m; 
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>p[i];
    bf();
    // int mul = 1;
    // for(int i=1;i<=m;i++) mul = mul * fastpow(p[i],i) % mod;
    // int ans = 0;
    // for(int i=1;i<=n;i++){
    //     ans += (long long) ceil(log2(mul) / log2(a[i]));
    //     // cout << ans << "\n";
    //     ans %= mod; 
    // }
    // cout << ans << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)
        solve();
    return 0;
}
