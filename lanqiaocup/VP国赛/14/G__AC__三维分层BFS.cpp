#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e3 + 10, INF = 0x3f3f3f3f3f3f3f3f;
int n,m,k;
int ans = INF;
int dist[N][N][22];
int g[N][N]; // 0A 1B

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

struct Node{
    int x,y,dep;
};

// O(nmk)
void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++){
            char c; cin>>c;
            if(c == 'A') g[i][j] = 0;
            else g[i][j] = 1;
        }
    
    memset(dist, -1, sizeof dist);
    queue<Node> q;
    dist[1][1][1] = 0;
    q.push({1,1,1});
    
    while(q.size()){
        int x = q.front().x, y = q.front().y, dep = q.front().dep; q.pop();
        debug(x, y, dep, dist[x][y][dep]);

        for(int i=0;i<4;i++){
            int u = x + dx[i], v = y + dy[i];
            if(u >= 1 && u <= n && v >= 1 && v <= m){
                if(dep + 1 <= k && dist[u][v][dep+1] == -1 && g[u][v] == g[x][y]){
                    dist[u][v][dep+1] = dist[x][y][dep] + 1;
                    q.push({u,v,dep+1});
                }else if(dep + 1 > k && dist[u][v][1] == -1 && g[u][v] == !g[x][y]){
                    debug(x, y, dep, dist[x][y][dep]);
                    debug(u, v);
                    dist[u][v][1] = dist[x][y][dep] + 1;
                    q.push({u,v,1});
                }
            }
        } 
    }
    
    for(int dep=1;dep<=k;dep++) if(dist[n][m][dep] != -1) {
        ans = min(ans, dist[n][m][dep]);
    }
    if(ans == INF) ans = -1;
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
