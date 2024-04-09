#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 10;
int n;
int depth[N];
int ans[N];
vector<int> g[N];

void dfs(int u,int f){
    for(auto &v : g[u]){
        if(v == f) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

void solve(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){ // 枚举以i为根
        depth[i] = 1;
        dfs(i, i);
        sort(depth + 1, depth + 1 + n);
        int s = 0;
        for(int k=1;k<=n;k++) { // ans[k] 取前k个点
            s += depth[k];
            ans[k] = max(ans[k], (n + 1) * k - 2 * s);
        }
    }
    for(int i=0;i<=n;i++) cout << ans[i] << " "; cout << "\n";
}

signed main(){
    solve();
    return 0;
}
