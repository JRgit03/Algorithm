#include <bits/stdc++.h>
using namespace std;
const int N = 404;
int n,m,x,y;
int dist[N][N];

int dx[] = {-2,-1,1,2,2,1,-1,-2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};

void bfs(){
    memset(dist,-1,sizeof dist);
    queue<pair<int,int>> q;
    dist[x][y] = 0;
    q.push({x,y});
    while(q.size()){
        auto [x,y] = q.front(); q.pop();
        for(int i=0;i<8;i++){
            int u = x + dx[i] , v = y + dy[i];
            if(u>=1&&u<=n&&v>=1&&v<=m&&dist[u][v]==-1){
                dist[u][v] = dist[x][y] + 1;
                q.push({u,v});
            }
        }
    }
}

int main(){
    cin>>n>>m>>x>>y;
    bfs();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cout << dist[i][j] << " \n"[j==m];
    return 0;
}
