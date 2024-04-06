/**
 * 题意：给定n*m的地图 0表示海水,1表示陆地,地图四周可视为海水,统计外岛个数,(内岛不算)
 *      n,m <= 50
 * 思路：从边界外的海水开始8连通bfs_on_sea,遇到陆地进行4连通bfs_on_load,标记访问过的点,由于是从边界开始bfs自然不会统计到内岛
*/
const int N = 55;
typedef pair<int,int> PII;
int n,m,ans
int vis[N][N];
int g[N][N];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int dx2[] = {-1,-1,-1,0,1,1,1,0};
int dy2[] = {-1,0,1,1,1,0,-1,-1};

void bfs_on_land(int sx,int sy){
    queue<PII> q;
    q.push({sx,sy});
    vis[sx][sy] = 1;
    while(q.size()){
        int x = q.front().first, y = q.front().second; q.pop();
        for(int i=0;i<4;i++){
            int u = x + dx[i], v = y + dy[i];
            if(u < 1 || u > n || v < 1 || v > m) continue;
            if(g[u][v] == 0) continue;
            if(vis[u][v]) continue;
            vis[u][v] = 1;
            q.push({u,v});
        }
    }
} 

void bfs_on_sea(int sx,int sy){
    queue<PII> q;
    q.push({sx,sy});
    vis[sx][sy] = 1;
    while(q.size()){
        int x = q.front().first, y = q.front().second; q.pop();
        for(int i=0;i<8;i++){
            int u = x + dx2[i], v = y + dy2[i];
            if(u < 0 || u > n+1 || v < 0 || v > m+1) continue;
            if(vis[u][v]) continue;
            vis[u][v] = 1;

            if(g[u][v] == 0) q.push({u,v});
            else{
                bfs_on_land(u,v);
                ans += 1;
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    ans = 0;
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=m+1;j++)
            g[i][j] = vis[i][j] = 0;
    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++)
            g[i][j] = s[j-1] - '0';
    }
    bfs_on_sea(0,0);
    cout << ans << "\n";
}