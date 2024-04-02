#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10, M = 1e5 +10, up = 1e4;
int n,m;
int c[N][N];
int x[M],y[M];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>x[i]>>y[i];
        c[x[i]][y[i]] += 1;
    }
    cin>>m;
    while(m--){
        int a,b,r; cin>>a>>b>>r;
        for(int i=max(0, a-r);i<=min(up,a+r);i++){
            for(int j=max(0, b-r);j<=min(up,b+r);j++){
                int dx = i - a, dy = j - b;
                if(1LL * dx * dx + 1LL * dy * dy <= 1LL * r * r){
                    c[i][j] = 0;
                }
            }
        }
    }
    int ans = 0;
    for(int i=0;i<=up;i++)
        for(int j=0;j<=up;j++)
            ans += c[i][j];
    cout << ans << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
