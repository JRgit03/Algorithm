#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve(){
    int n,k;cin>>n>>k;
    vector<int> a(n+1),ans(n);
    int sum = 0;
    for(int i=0;i<n;i++) cin>>a[i] , sum += a[i];
    a[n] = (0 + n) * (1 + n) / 2 - sum;
    for(int i=0;i<n;i++) ans[i] = a[(i-k+(n+1)*k)%(n+1)];
    for(int i=0;i<n;i++) cout << ans[i] << " \n"[i==n-1];
}
signed main(){
    IOS;
    int t;cin>>t;
    while(t--) solve();
    return 0;
}
