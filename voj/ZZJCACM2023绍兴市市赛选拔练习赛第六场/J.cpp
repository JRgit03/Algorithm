#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 10;
int ans[maxn];

void solve(){ 
    int n; cin>>n;
    string s; cin>>s; s = "?" + s;
    int tar = (1 + n) * n / 2;
    // cout << s << " " << tar << "\n";
    if(tar % 2 == 1){
        cout << -1 << "\n";
        return;
    }
    tar /= 2;
    for(int i=1;i<=n;i++) ans[i] = 0;
    int x = n;
    // 1 男 -> (g3 g4)
    // 0 女 -> (g1 g2)
    while(tar > 0){
        if(tar >= x){
            ans[x] = (s[x] == '1' ? 3 : 1);
            tar -= x;
            x--;
        }else x = tar;
    }
    for(int i=1;i<=n;i++) 
        if(ans[i] == 0)
            ans[i] = (s[i] == '1' ? 4 : 2);
    for(int i=1;i<=n;i++) cout << ans[i]; cout << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;cin>>t;
    while(t--)
        solve();
    return 0;
}
