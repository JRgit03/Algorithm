#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e2 + 10, INF = 0x3f3f3f3f3f3f3f3f;
int n;
int sx,sy,ex,ey;
int g[N][N];
int dist[N][N];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

struct Node{
    int x,y,f;
};

int ans = INF;
void bfs(int x,int y){
    memset(dist, 0x3f, sizeof dist);
    dist[sx][sy] = 0;
    queue<Node> q;  q.push({sx,sy,g[sx][sy]});
    
    while(q.size()){
        auto [x,y,f] = q.front(); q.pop();
        
        for(int i=0;i<4;i++){
            int u = x + dx[i], v = y + dy[i];
            if(u >= 1 && u <= n && v >= 1 && v <= n 
                && dist[u][v] > dist[x][y] + 1 && (g[x][y] == 0 || g[u][v] == 0 || g[u][v] == -g[x][y])){
                dist[u][v] = dist[x][y] + 1;
                q.push({u,v,g[u][v]});
            }
        }
    }

    ans = min(ans, dist[ex][ey]);
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            char c; cin>>c;
            if(c == 'A') sx = i, sy = j, g[i][j] = 0;
            else if(c == 'B') ex = i, ey = j, g[i][j] = 0;
            else g[i][j] = (c == '+' ? 1 : -1);
        }
    bfs(sx, sy);
    if(ans == INF) cout << -1 << "\n";
    else cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
