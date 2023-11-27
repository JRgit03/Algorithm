#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 10;

int a[maxn];
int cnt[maxn];
int f[maxn]; // f[x]: gcd=x 对数贡献 => f[x] = g[x] - f[2x] - f[3x] ...
int g[maxn]; // g[x]: gcd=x 的倍数 的对数贡献 => g[x] = f[x] + f[2x] + f[3x] ...

vector<int> factor[maxn]; // fact[x]:x的所有因子

void solve(){
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]; sort(a+1,a+1+n);
    for(int i=1;i<=100000;i++) f[i] = g[i] = cnt[i] = 0;
    for(int i=1;i<=n;i++){
        for(auto x : factor[a[i]]){ // x | a[i]
            g[x] += cnt[x] * (n - i);
            cnt[x] += 1;
        }
    }
    int ans = 0;
    for(int i=100000;i>=1;i--){
        f[i] = g[i];
        for(int j=i+i;j<=100000;j+=i){
            f[i] -= f[j];
        }
        ans += f[i] * i;
    }
    cout << ans << "\n";
}

signed main(){
    for(int i=1;i<=100000;i++)
        for(int j=i;j<=100000;j+=i)
            factor[j].push_back(i);
    int t; cin>>t;
    while(t--) 
        solve();
    return 0;
}

// b整除a 记 b | a, 即 b 是 a 的因子