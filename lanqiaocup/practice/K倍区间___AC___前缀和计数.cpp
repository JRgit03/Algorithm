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

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>a[i]; 
        a[i] %= k;
    }
    map<int,int> mp; mp[0] = 1;
    int ans = 0, sum = 0;
    for(int i=1;i<=n;i++){
        sum = (sum + a[i]) % k;
        ans += mp[sum];
        mp[sum] += 1;
    }
    cout << ans << "\n";
}
    

signed main(){
    IOS;
    solve();
    return 0;
}
