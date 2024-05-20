#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e5 + 10;
int n,m;
int a[N],b[N];

// 目标数组a = b => 从前往后必然满足ai=bi, 那么a1=b1必然相同 不同则从后面往前合并
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    int ans = 0,i = 1,j = 1, s0 = 0, s1 = 0;
    while(i <= n && j <= m){
        s0 += a[i], s1 += b[j];
        if(s0 == s1) i += 1, j += 1, s0 = 0, s1 = 0;
        else if(s0 > s1){
            ans += 1;
            s0 -= a[i]; j += 1;
        }else if(s0 < s1){
            ans += 1;
            s1 -= b[j]; i += 1;
        }
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
