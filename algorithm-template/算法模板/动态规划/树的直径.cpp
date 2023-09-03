#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 1e4 + 10;
int n,m;
int d1[N],d2[N]; //d[u] 以u为根节点 d1 最长路 d2 次长路
int dist[N]; 
int ans;

vector<pair<int,int>> g[N];

void dfs(int u,int fa){
    d1[u] = d2[u] = 0;
    for(auto &[v,w] : g[u]){
        if(v == fa) continue;
        dfs(v,u);
        int t = d1[v] + w; // w = 1 即为 特殊化边权为1
        if(t > d1[u]) d2[u] = d1[u] , d1[u] = t;
        else if(t > d2[u]) d2[u] = t; 
    }
    ans = max(ans,d1[u] + d2[u]);
}

void solve(){
    cin>>n; m = n - 1;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w}) , g[v].push_back({u,w});
    }
    dfs(1,-1);
    cout << ans << "\n";
}

int main(){
    IOS;solve();
    return 0;
}
