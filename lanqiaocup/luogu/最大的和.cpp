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
int a[N],b[N],c[N],s[N];

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    int ans = 0, sum = 0;
    for(int i=1;i<=n;i++) {
        if(b[i] == 1) c[i] = 0, sum += a[i];
        else c[i] = a[i], sum += 0;
        c[i] += c[i-1];
    }
    for(int r=1;r<=n;r++){
        if(r >= k){
            int l = r - k + 1;
            ans = max(ans, c[r] - c[l-1] + sum);
        }
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
