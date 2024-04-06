#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n; cin>>n;
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        int a,c; cin>>a>>c;
        mp[c].push_back(a);
    }
    int ans = 0;
    for(auto &[c, v] : mp) ans = max(ans, *min_element(v.begin(), v.end()));
    cout << ans << "\n";
}

signed main(){
    solve();
    return 0;
}
