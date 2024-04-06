#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e2 + 10;
int n,m;
int sx,sy,ex,ey;
char g[N][N];
int e[N][N];
int vis[N][N];

int d[N][N]; // d[i,j]到达点i,j的最大剩余体力数
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

struct Node{
    int x,y,v;
    bool operator < (const Node& o) const {
        return v < o.v; 
    }
};

void bfs(int sx,int sy){
    priority_queue<Node> heap;
    vis[sx][sy] = 1;
    heap.push({sx,sy,0});
    while(heap.size()){
        auto [x,y,w] = heap.top(); heap.pop();
        d[x][y] = max(d[x][y], max(w, e[x][y]));
        if(d[x][y] <= 0) continue;
        
        for(int i=0;i<4;i++){
            int u = x + dx[i], v = y + dy[i];
            if(u <= 0 || u > n || v <= 0 || v > m) continue;
            if(g[u][v] == '#') continue;
            
            if(!vis[u][v]){
                vis[u][v] = 1;
                d[u][v] = d[x][y] - 1;
                heap.push({u,v,d[u][v]});
            }
            if(vis[u][v] && d[x][y] - 1 > d[u][v]){
                d[u][v] = d[x][y] - 1;
                heap.push({u,v,d[u][v]});
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            char c; cin>>c; g[i][j] = c;
            if(c == 'S') sx = i, sy = j;
            if(c == 'T') ex = i, ey = j;
        }
    int q;cin>>q;
    while(q--){
        int r,c,w; cin>>r>>c>>w;
        e[r][c] = w; 
    }
    bfs(sx,sy);
    cout << (vis[ex][ey] ? "Yes" : "No") << "\n";
}

signed main(){
    solve();
    return 0;
}
