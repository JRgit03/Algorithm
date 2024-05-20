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
int n,k;
int a[N];
int b[N];

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans = 0, cnt = 0;
    for(int r=1,l=1;r<=n;r++){
        b[a[r]] += 1;
        if(b[a[r]] == 1 && a[r] <= k) cnt += 1;
        debug(l, r, cnt);
        if(r >= k){
            if(cnt == k) ans += 1;
            b[a[l]] -= 1;
            if(b[a[l]] == 0 && a[l] <= k) cnt -= 1;
            l += 1;
        } 
    }     
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
