#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn],b[maxn];

void solve(){
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    map<int,int> cnt;
    for(int i=1;i<=n;i++) cnt[a[i]-b[i]] += 1;
    int ans = 0;
    for(auto [_,sz] : cnt) ans = max(ans, sz);
    cout << ans << "\n";
}

int main(){
    int t; cin>>t;
    while(t--) 
        solve();
    return 0;
}
