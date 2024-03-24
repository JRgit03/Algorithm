#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
int n,m;
char g[N][N];
char col = '0';

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

void dfs(int x,int y,char col){
    g[x][y] = col;
    for(int i=0;i<4;i++){
        int u = x + dx[i], v = y + dy[i];
        if(u >= 1 && u <= n && v >= 1 && v <= m && g[u][v] == 'X'){
            dfs(u,v,col);
        } 
    }
}

struct Node{
    int x,y,d;
};

int vis[N][N];
int bfs(int x,int y){
    memset(vis, 0, sizeof vis);
    queue<Node> q;
    q.push({x,y,0});
    vis[x][y] = 1;
    while(q.size()){
        auto [x,y,d] = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int u = x + dx[i], v = y + dy[i];
            if(u >= 1 && u <= n && v >= 1 && v <= m && !vis[u][v]){
                if(g[u][v] == '2') return d;
                vis[u][v] = 1;
                q.push({u,v,d+1});
            } 
        }
    }
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>g[i][j];
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++)
            if(g[i][j] == 'X')    
                dfs(i,j,++col);
    int ans = INT_MAX;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(g[i][j] == '1')
                ans = min(ans, bfs(i,j));
    cout << ans << "\n";
}

signed main(){
    solve();
    return 0;
}
