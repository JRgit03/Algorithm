#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e5 + 10;
int n,m;
int col[N]; // col -1未染色 0白 1黑
vector<int> g[N];

int dfs(int u,int c){
    col[u] = c;
    for(auto &v : g[u]){
        if(col[v] == -1){
            if(!dfs(v, !c)) return 0;
        }else if(col[v] == c) return 0;
    }
    return 1;
}

void solve(){
    memset(col, -1, sizeof col);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }
    for(int i=1;i<=n;i++) if(col[i] == -1) {
        if(!dfs(i, 0)){
            cout << "No" << "\n";
            return; 
        }
    }
    cout << "Yes" << "\n";
    return;
}

signed main(){
    IOS;
    solve();
    return 0;
}
