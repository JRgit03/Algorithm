#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 1e2 + 10;
int n,m;
int sx,sy,ex,ey;
string g[N];
int dist[N][N];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) dist[i][j] = -1;
    for(int i=0;i<n;i++) {
        cin>>g[i];
        for(int j=0;j<m;j++) {
            if(g[i][j] == 'S') sx = i, sy = j;
            if(g[i][j] == 'E') ex = i, ey = j;
        }
    }
    
    queue<pair<int,int>> q;
    dist[sx][sy] = 0;
    q.push({sx, sy});
    
    while(q.size()){
        auto [x, y] = q.front(); q.pop();
        
        for(int i=0;i<4;i++){
            int u = x + dx[i], v = y + dy[i];
            if(u >= 0 && u < n && v >= 0 && v < m && dist[u][v] == -1 && g[u][v] != '#'){
                dist[u][v] = dist[x][y] + 1;
                q.push({u, v});
            } 
        }
    }
    cout << dist[ex][ey] << "\n";
}

signed main(){
    IOS;
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
