#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve(){
    int n,m; cin>>n>>m;
    string x,s; cin>>x>>s;
    int ans = 0;
    while(x.length() <= 32 * m){
        if(x.find(s) != -1){
            cout << ans << "\n";
            return;
        }
        ans += 1;
        x = x + x;
    }
    cout << -1 << "\n";
    return;
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
