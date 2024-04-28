#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m; cin>>n>>m;
    vector<string> g(5); for(auto &s : g) cin>>s;
    int c1 = 0, c2 = 0;
    for(int i=0;i<n;i++){
        if(g[1][i] == '*'){
            c1 += 1;
            if(g[0][i] == '*') c1 += 1;
        }else if(g[0][i] == '*') c2 += 1;
        if(g[3][i] == '*'){
            c1 += 1;
            if(g[4][i] == '*') c1 += 1;
        }else if(g[4][i] == '*') c2 += 1;
    }
    int ans = (c1 >= m ? m : c1 + min(c2, (m - c1) / 2));
    cout << ans << "\n";
}

signed main(){
    solve();
    return 0;
}
