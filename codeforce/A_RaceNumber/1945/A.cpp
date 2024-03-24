#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

void solve(){
    int a,b,c; cin>>a>>b>>c;
    int ans = a;
    if(b % 3 != 0){
        ans += b / 3;
        int x = b % 3;
        if((x + c) <= 2){
            cout << -1 << "\n";
            return;
        }else{
            c -= (3 - x);
            ans += 1;
            ans += c / 3 + (c % 3 != 0);
        }
    }else{
        ans += b / 3 + c / 3 + (c % 3 != 0);
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    int t; cin>>t;
    while(t--) 
        solve();
    return 0;
}
