// https://www.lanqiao.cn/problems/89/learning/?page=1&first_category_id=1&second_category_id=3
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 22;
int n;
int tarx[N],tary[N],curx[N],cury[N];
int f;
int vis[N][N];
vector<int> path;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int get(int x,int y){
    return x * n + y;
}

void dfs(int x,int y){
    if(f) return;
    if(curx[x] > tarx[x] || cury[y] > tary[y]) return;
    if(x == n - 1 && y == n - 1){
        int suc = 1;
        for(int i=0;i<n;i++) 
            suc &= (curx[i] == tarx[i] && cury[i] == tary[i]);
        if(suc){
            for(auto &v : path) cout << v << " ";
            f = 1;
        }
        debug(f);
        debug(path);
        return;
    }
    for(int i=0;i<4;i++){
        int u = x + dx[i], v = y + dy[i];
        if(u >= 0 && u < n && v >= 0 && v < n && !vis[u][v]){
            curx[u]++, cury[v]++, vis[u][v] = 1; path.push_back(get(u,v));
            dfs(u,v);
            curx[u]--, cury[v]--, vis[u][v] = 0; path.pop_back();
        }
    }
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>tary[i];
    for(int i=0;i<n;i++) cin>>tarx[i];
    curx[0]++, cury[0]++, vis[0][0] = 1; path.push_back(get(0,0));
    dfs(0,0);
    curx[0]--, cury[0]--, vis[0][0] = 0; path.pop_back();
}

signed main(){
    IOS;
    solve();
    return 0;
}
