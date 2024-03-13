#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> a(n); for(auto &x : a) cin>>x;
    int ans = 1e9;
    for(int i=1;i<n;i++){
        if(a[i] < a[i-1]) ans = 0;
        else ans = min(ans, (a[i] - a[i-1] + 1 + !((a[i] - a[i-1]) & 1)) / 2);
    }
    cout << ans << "\n";
}

signed main(){
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
