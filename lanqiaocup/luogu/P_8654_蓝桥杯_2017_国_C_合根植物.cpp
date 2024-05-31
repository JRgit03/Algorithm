#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e3 + 10;
int n,m;
int vis[N * N];
vector<int> g[N * N];

void dfs(int u){
    for(auto &v : g[u]){
        if(vis[v]) continue;
        vis[v] = 1;
        dfs(v);
    }
}

void solve(){
    cin>>n>>m;
    int k; cin>>k;
    for(int i=0;i<k;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }    
    int ans = 0;
    for(int i=1;i<=n*m;i++) if(!vis[i]) {
        vis[i] = 1;
        ans += 1;
        dfs(i);
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
