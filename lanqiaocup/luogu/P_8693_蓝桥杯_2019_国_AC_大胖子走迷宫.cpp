#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 3e2 + 10;
int n,k;
int sx,sy,ex,ey;
char g[N][N];
int vis[N][N];
int dist[N][N];

struct Node{
    int x,y,t;
};

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int check(int x,int y,int t){
    if(vis[x][y]) return 0;
    int suc = 1, m = 0;

    if(t < k) m = 2;
    else if(t < 2 * k) m = 1;
    else m = 0;

    for(int i=x-m;i<=x+m;i++)
            for(int j=y-m;j<=y+m;j++)
                if(!(i >= 1 && i <= n && j >= 1 && j <= n && g[i][j] == '+')) suc = 0;
                
    return suc;
}
 
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>g[i][j];
    sx = 3, sy = 3, ex = n - 2, ey = n - 2;
    memset(dist, 0x3f, sizeof dist);
    queue<Node> q;
    vis[sx][sy] = 1;
    dist[sx][sy] = 0;
    q.push({sx,sy,0});
    
    while(q.size()){
        auto [x,y,t] = q.front(); q.pop();

        for(int i=0;i<4;i++){
            int u = x + dx[i], v = y + dy[i];
            if(check(u,v,t)){ // 为什么是t而不是t+1 t是当前时刻去移动的！
                vis[u][v] = 1;
                dist[u][v] = t + 1;
                q.push({u,v,t+1});
            }
        }        

        if(t + 1 <= 2 * k) q.push({x,y,t+1}); // 重点优化!
    }

    cout << dist[ex][ey] << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
