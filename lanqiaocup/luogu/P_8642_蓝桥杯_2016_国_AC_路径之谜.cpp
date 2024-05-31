#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 22;
int n;
int tarx[N], tary[N], curx[N], cury[N];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int suc;
int vis[N][N];
vector<pair<int,int>> path;

void dfs(int x,int y){
    if(suc) return;
    if(x == n - 1 && y == n - 1){
        int f = 1;
        for(int i=0;i<n;i++) f &= (curx[i] == tarx[i]);
        for(int i=0;i<n;i++) f &= (cury[i] == tary[i]);
        if(f) {
            suc = 1;
            for(auto &[x, y] : path) cout << x * n + y << " ";
        }
        return;
    }

    for(int i=0;i<4;i++){   
        int u = x + dx[i], v = y + dy[i];
        if(u >= 0 && u < n && v >= 0 && v < n && !vis[u][v] && curx[u] + 1 <= tarx[u] && cury[v] + 1 <= tary[v]){
            vis[u][v] = 1, curx[u] += 1, cury[v] += 1; path.push_back({u,v});
            dfs(u,v); 
            vis[u][v] = 0, curx[u] -= 1, cury[v] -= 1; path.pop_back();
        }
    }
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>tary[i];
    for(int i=0;i<n;i++) cin>>tarx[i];
    vis[0][0] = 1, curx[0] += 1, cury[0] += 1; path.push_back({0,0});
    dfs(0,0); 
    vis[0][0] = 0, curx[0] -= 1, cury[0] -= 1; path.pop_back();
}

signed main(){
    IOS;
    solve();
    return 0;
}
