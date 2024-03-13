#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int a,b,c; cin>>a>>b>>c;
    int ans = 0;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        ans += (x >= b && x <= c);
    }
    cout << ans << "\n";
}

signed main(){
    solve();
    return 0;
}
