#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 15;
int n,k;
int suc;
int g[N][N];
int vis[N][N];
int st[N][N][N][N];
vector<int> path;

int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};


void dfs(int x,int y){
	//cerr << "dfs: " <<  x << " " << y << " " << path.size() << "\n";
    if(suc) return;
    if(x == n && y == n && path.size() == n * n - 1) {
        suc = 1;
        for(auto &x : path) cout << x; cout << "\n";
        return;
    }
    for(int i=0;i<8;i++){
        int u = x + dx[i],v = y + dy[i];
        if(u >= 1 && u <= n && v >= 1 && v <= n && !vis[u][v] 
        && g[u][v] == (g[x][y] + 1) % k){
            if(i & 1){
                int u1 = x + dx[i - 1], v1 = y + dy[i - 1];
                int u2 = x + dx[(i + 1) % 8], v2 = y + dy[(i + 1) % 8];
                if(st[u1][v1][u2][v2] > 0 || st[u2][v2][u1][v1] > 0) continue;
                path.push_back(i);
                vis[u][v] = 1;
                st[x][y][u][v]++;
                st[u][v][x][y]++;
                dfs(u,v);
                st[x][y][u][v]--;
                st[u][v][x][y]--;
                vis[u][v] = 0;
                path.pop_back(); 
            }else{
                path.push_back(i);
                vis[u][v] = 1;
                dfs(u,v);
                vis[u][v] = 0;
                path.pop_back(); 
            }
        } 
    }
}

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>g[i][j];
    if(g[1][1] != 0 || n == 1) {
        cout << -1 << "\n";
        return;
    }
    vis[1][1] = 1;
    dfs(1,1);  
    vis[1][1] = 0;
    //cerr << "suc: " << suc << "\n"; 
    if(!suc) cout << -1 << "\n";  
}


// AC 100 point
signed main(){
    IOS;
    solve();
    return 0;
} 
/*
3 3
0 2 0
1 1 1
2 0 2
*/
