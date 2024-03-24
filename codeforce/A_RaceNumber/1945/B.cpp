#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

void solve(){
    int a,b,m; cin>>a>>b>>m;
    cout << m / a + m / b + 2 << "\n";
}

signed main(){
    IOS;
    int t; cin>>t;
    while(t--) 
        solve();
    return 0;
}
