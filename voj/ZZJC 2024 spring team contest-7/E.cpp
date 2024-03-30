#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> h(n); for(auto &x : h) cin>>x;
    sort(h.begin(), h.end());
    int ans = n, r = 1;
    for(int i=0;i<n;i++){
        r = h[i];
        ans = min(ans, r + n - i - 1);
    }
    cout << ans << "\n";
}

signed main(){
    solve();
    return 0;
}
