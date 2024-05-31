#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e3 + 10;
int n,m;
int del;
int vis[N];
vector<int> g[N];

void dfs(int u){
    for(auto &v : g[u]){
        if(vis[v] || v == del) continue;
        vis[v] = 1;
        dfs(v);
    }
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }
    
    int a,b; cin>>a>>b;
    for(int j=1;j<=n;j++) vis[j] = 0;
    vis[a] = 1;
    dfs(a);
    if(!vis[b]){
        cout << -1 << "\n";
        return;
    }

    int ans = 0;
    for(int i=1;i<=n;i++){
        if(i == a || i == b) continue;
        for(int j=1;j<=n;j++) vis[j] = 0;
        del = i;
        vis[a] = 1;
        dfs(a);
        ans += !vis[b];
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
