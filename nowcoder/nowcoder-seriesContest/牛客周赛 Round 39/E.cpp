#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,m,p,x; cin>>n>>m>>p>>x;
    int ans = 0;
    for(int a=1;a<=n;a++){
        for(int b=1;b<=m;b++){
            if(x - a * b <= 0) continue;
            if((x - a * b) % (2 * (a + b)) != 0) continue;
            if((x - a * b) / (2 * (a + b)) > p) continue;
            ans += 1; 
        }
    }
    cout << ans << "\n";
}

signed main(){
    solve();
    return 0;
}
