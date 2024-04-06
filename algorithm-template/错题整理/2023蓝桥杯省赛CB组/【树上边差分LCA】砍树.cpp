/**
 * 题意：给定n点n-1边的树，和m个不重复无序点对(a1,b1),(a2,b2)...,其中ai互不相同,bi互不相同,ai!=bj
 *      给是否存在砍掉树上一边，使得所有无序点对不连通
 * 思路：树上边差分，对于所有点对ai,bi，给ai->bi的简单路径上的边权+1, 最后统计边权==m即是可行解，不存在输出-1
*/
const int N = 1e6 + 10;
int n,m;
int depth[N];
int fa[N][22];
vector<int> g[N];

// mp = {{{u,v},id}, ....} 边 -> id
// mp2 = {{{u,v},v}, ...} 边 -> 权值点, 边权下移给节点
map<pair<int,int>,int> mp, mp2;

void bfs(int sx){
    queue<int> q;
    q.push(sx);
    depth[sx] = 1;
    
    while(q.size()){
        int u = q.front(); q.pop();

        for(auto v : g[u]){
            if(depth[v] != 0) continue;
            depth[v] = depth[u] + 1;
            mp2[{u,v}] = v;
            q.push(v);
            fa[v][0] = u;
            for(int k=1;k<=20;k++) fa[v][k] = fa[fa[v][k-1]][k-1];
        }
    }
}

int lca(int a,int b){
    if(depth[a] < depth[b]) swap(a, b);
    for(int k=20;k>=0;k--){
        if(depth[fa[a][k]] >= depth[b]){
            a = fa[a][k];
        }
    }
    if(a == b) return a;
    for(int k=20;k>=0;k--){
        if(fa[a][k] != fa[b][k]){
            a = fa[a][k];
            b = fa[b][k];
        }
    }
    return fa[a][0];
}


int val[N];
void dfs(int u,int f){
    for(auto v : g[u]){
        if(v == f) continue;
        dfs(v,u);
        val[u] += val[v];
    }
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
        mp[{u,v}] = mp[{v,u}] = i+1;
    }    
    bfs(1);
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        val[a] += 1; val[b] += 1; val[lca(a,b)] -= 2;
    }
    dfs(1,1);
    int ans = -1;
    for(auto &item : mp){
        int u = item.first.first, v = item.first.second, id = item.second;
        if(mp2.count({u,v})){
            int x = mp2[{u,v}];
            if(val[x] == m && id > ans){
                ans = id;
            }
        }
    }
    cout << ans << "\n";
}