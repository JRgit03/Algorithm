#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define dbug(x) cout << #x << '=' << x << endl
#define int long long
#define x first
#define y second
#define ONLINE_JUDGE  
using namespace std;
const int N = 5e2 + 10, Mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
typedef pair<int,int> PII;
typedef long long ll;
int n,m;
int flag;
string g[N];
int vis[N][N];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
string op = "snuke";

void dfs(int x,int y,int t){
    if(flag) return; 
    if(x == n-1 && y == m-1) flag = 1;
    for(int i=0;i<4;i++){
        int u = x + dx[i] , v = y + dy[i];
        if(u>=0&&u<n&&v>=0&&v<m&&!vis[u][v]&&g[u][v]==op[t]){
            vis[u][v] = 1;
            dfs(u,v,(t+1)%5);
        }
    }
}

void bfs(int x,int y,int t){
    queue<tuple<int,int,int>> q; q.push({x,y,t});
    while(q.size()){
        auto [x,y,t] = q.front(); q.pop();
        if(x == n-1 && y == m-1) flag = 1;
        for(int i=0;i<4;i++){
            int u = x + dx[i] , v = y + dy[i];
            if(u>=0&&u<n&&v>=0&&v<m&&!vis[u][v]&&g[u][v]==op[t]){
                vis[u][v] = 1;
                q.push({u,v,(t+1)%5});
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>g[i];
    vis[0][0] = 1; if(g[0][0] == 's') bfs(0,0,1);
    cout << (flag ? "Yes" : "No") << "\n";
}

signed main(){
    IOS; solve();
    return 0;
}
