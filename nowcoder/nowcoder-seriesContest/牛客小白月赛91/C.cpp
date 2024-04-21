#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m,k; cin>>n>>m>>k;
    int t = max(n / 2, m / 2);
    int ans = 0;
    while(k--){
        int x,y; cin>>x>>y;
        int s = abs(x - (n/2+1)) + abs(y - (m/2+1));
        ans += (s <= t);
    }
    cout << ans << "\n";
}

int main(){
    solve();
    return 0;
}