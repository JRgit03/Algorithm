#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e5 + 10, up = 1e5;
int n,k;
int a[N];
int cnt[N];

int val[N];
int dp[N];

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]] += 1;
    }    
    if(k == 0){
        int ans = 0;
        for(int i=0;i<=up;i++) if(cnt[i] > 0) {
            ans += 1;
        } 
        cout << ans << "\n";
        return;
    }
    //将数字分为k-1组 1~k-1 
    //第i组存 i, i+k, i+2*k, ... 显然不同组之间互不干扰, 每个组尽可能选多的数字
    // eg: 0, 0+k, 0+2*k, ...  1, 1+k, 1+2*k, ...
    //对于第i组 dp[j]表示以第j个数为结尾 选或不选 dp[j] = max(dp[j-1], dp[j-2] + val[j])
    int ans = 0;
    for(int i=0;i<k;i++){ 
        int m = 0;
        for(int j=i;j<=up;j+=k) val[++m] = cnt[j];
        for(int j=1;j<=m;j++) {
            dp[j] = max(dp[j - 1], (j - 2 >= 0 ? dp[j - 2] : 0) + val[j]);
        }
        ans += dp[m];
    }
    cout << ans << "\n";
} 

signed main(){
    IOS;
    solve();
    return 0;
}
