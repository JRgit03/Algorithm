#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define int long long
using namespace std;

int max(int a,int b){return (a > b ? a : b); }
int min(int a,int b){return (a < b ? a : b); }

const int N = 55;
typedef pair<int,int> PII;
int n,m;
int ans;
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

signed main(){
    IOS; 
    int t; cin>>t;
    while(t--) solve();
    return 0;
} 