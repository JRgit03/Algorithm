#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;

int dx[8] = {1,-1,1,-1,2,-2,2,-2};
int dy[8] = {2,2,-2,-2,1,1,-1,-1};

int vis[N][N];

void solve(){
    int n,m;
    for(n=1;n<=10;n++){
        for(m=n;m<=10;m++){
            for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) vis[i][j] = 0;
            int ans = 0;
            function<void(int,int)> dfs = [&](int x,int y) -> void {
                for(int i=0;i<8;i++){
                    int u = x + dx[i], v = y + dy[i];
                    if(u >= 1 && u <= n && v >= 1 && v <= m && !vis[u][v]){
                        vis[u][v] = 1;
                        ans += 1;
                        dfs(u,v);
                    }
                }
            }; 
            dfs(1,1); 
            cout << n << " " << m << " " << ans << "\n";
        }
    }
}

int main(){
    // int t; cin>>t;
    // while(t--) solve();
    return 0;
}
