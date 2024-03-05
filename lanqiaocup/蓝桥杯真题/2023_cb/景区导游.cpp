#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n,k;
vector<pair<int,int>> g[N];
int a[N];
int depth[N]; // depth[u] 点1->点u的深度
int dist[N]; // dist[u] 点1->点u的距离
int fa[N][25]; // fa[u][k] 从u节点往上跳2^k下到达的点

void bfs(int root){
    memset(depth,0x3f,sizeof depth);
    memset(dist,0x3f,sizeof dist);
    depth[0] = 0; //哨兵
    depth[root] = 1; 
    dist[0] = 0;
    dist[root] = 0;
    queue<int> q;
    q.push(root);
    
    while(q.size()){
        int u = q.front(); q.pop();
        for(auto &[v,w] : g[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                depth[v] = depth[u] + 1;
                q.push(v);
                fa[v][0] = u;
                for(int k=1;k<=20;k++){
                    fa[v][k] = fa[fa[v][k-1]][k-1];
                }
            }
        }
    }
}

int lca(int a,int b){
    if(depth[a] <= depth[b]) swap(a,b);
    for(int k=20;k>=0;k--){
        if(depth[fa[a][k]] >= depth[b]){
            a = fa[a][k];
        }
    }
    if(a == b) return a;
    for(int k=20;k>=0;k--){
        if(fa[a][k] != fa[b][k]){ //不相等才跳 相等可能是跳过头了
            a = fa[a][k];
            b = fa[b][k];
        }
    }    // 最终跳到LCA的下一层

    return fa[a][0];
}

// 计算 u -> v 距离
int calc(int u,int v){
    // cout << u << " " << v << " " << lca(u,v) << "\n";
    // cout << "dist(" << u << "->" << v << ")" << " " << depth[u] + depth[v] - 2 * depth[lca(u,v)] << "\n";
    return dist[u] + dist[v] - 2 * dist[lca(u,v)];
}

int ans[N];

void solve(){
    cin>>n>>k;
    for(int i=0;i<n-1;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }        
    for(int i=1;i<=k;i++) cin>>a[i]; 
    bfs(1);
    int sum = 0;
    for(int i=2;i<=k;i++){
        sum += calc(a[i-1], a[i]);
    }
    for(int i=1;i<=k;i++){
        ans[i] = sum;
        if(i - 1 >= 1) ans[i] -= calc(a[i-1], a[i]);
        if(i + 1 <= k) ans[i] -= calc(a[i], a[i+1]);
        if(i - 1 >= 1 && i + 1 <= k) ans[i] += calc(a[i-1], a[i+1]);
        cout << ans[i] << " ";
    }
}

signed main(){
    solve();
    return 0;
}
