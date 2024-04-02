#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
int n,m;
int d1[N],d2[N];
vector<int> g[N];

int maxlen;
void dfs(int u,int fa){
    d1[u] = d2[u] = 0;
    for(auto v : g[u]){
        if(v == fa) continue;
        dfs(v,u);
        int t = d1[v] + 1;
        if(t > d1[u]) d2[u] = d1[u] , d1[u] = t;
        else if(t > d2[u]) d2[u] = t; 
    }
    maxlen = max(maxlen, d1[u] + d2[u]);
}

void solve(){
    memset(d1, -1, sizeof d1);
    memset(d2, -1, sizeof d2);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v; u++; v++;
        g[u].push_back(v); g[v].push_back(u);
    } 
    int ans = 0;
    vector<int> vec; // vec[i] 第i个连通块的以中点为根的离叶子节点的最大距离
    for(int i=1;i<=n;i++){
        if(d1[i] == -1 && d2[i] == -1){
            maxlen = 0;
            dfs(i,i);
            ans = max(ans, maxlen);
            vec.push_back((maxlen + 1) / 2);
        }
    }

    sort(vec.begin(), vec.end(), greater<int>());
    int sz = vec.size();
    if(sz == 2) ans = max(ans, vec[0] + vec[1] + 1);
    else if(sz >= 3) ans = max({ans, vec[0] + vec[1] + 1, vec[1] + vec[2] + 2});
    cout << ans << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
