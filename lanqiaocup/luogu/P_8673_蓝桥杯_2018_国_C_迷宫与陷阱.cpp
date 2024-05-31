#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e3 + 10;
typedef pair<int,int> PII;
int n,k;
char g[N][N];
int vis[N][N]; // vis[i,j] 表示是否访问过点(i,j) vis值表示到达点i,j时最大的无敌步数,一个点可以达到多次
int dist[N][N];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

struct Node{
    int x,y,cnt;
};

void solve(){
    memset(vis, -1, sizeof vis);
    cin>>n>>k;
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=n;j++) 
            cin>>g[i][j];
    queue<Node> q;
    dist[1][1] = 0;
    vis[1][1] = 0;
    q.push({1,1,0});

    while(q.size()){
        auto [x,y,cnt] = q.front(); q.pop();
        
        for(int i=0;i<4;i++){ 
            int u = x + dx[i], v = y + dy[i];
            if(g[u][v] == 'X' && cnt == 0) continue;
            
            int cur = max(0, cnt - 1);
            if(g[u][v] == '%') cur = k;

            if(u >= 1 && u <= n && v >= 1 && v <= n && g[u][v] != '#' && vis[u][v] < cur){
                dist[u][v] = dist[x][y] + 1;
                vis[u][v] = cur;
                q.push({u,v,cur});
            }
        }
    }

    if(dist[n][n] == -1) cout << -1 << "\n";
    else cout << dist[n][n] << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}

/*
剪枝：加一个 int 型的数组vis，入队时需要 vis[x][y] < magic，即如果当前节点已经被访问过，
且之前到达该节点时的无敌状态剩余步数比现在要多，则不需要再次访问该节点。
因为如果我们之前已经访问过该节点并且使用了更多的无敌步数，那么这条路径一定不是最优解。初始时要赋值为全赋-1
*/
