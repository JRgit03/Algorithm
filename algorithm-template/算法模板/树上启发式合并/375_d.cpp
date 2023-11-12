/**
 * 现有一棵 n 个点的树，点的编号从 1 起，树以 1 为根，每个点 i 都一个颜色 ci，
 * 接下来有 m 个询问，每次询问以 vj为根的子树中，
 * 求有多少种颜色，这些颜色在子树中出现的次数至少为 kj。
 * https://codeforces.com/problemset/problem/375/D
 */
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int maxn = 1e5 + 10;
int n,m;

vector<int> g[maxn];

int siz[maxn],son[maxn];

void dfs_son(int u,int f){
    siz[u] = 1;
    int maxsize = -1;
    for(auto v : g[u]){
        if(v == f) continue;
        dfs_son(v,u);
        siz[u] += siz[v];
        if(siz[v] > maxsize){
            maxsize = siz[v];
            son[u] = v;
        }
    }
}

int col[maxn];
int ans[maxn];
int cnt[maxn]; // cnt[i]表示 '当前' 颜色i的出现次数
int vis[maxn]; // vis[i]表示 '当前' 颜色数>=i的个数 
int flag; // 重儿子标记
vector<pair<int,int>> q[maxn]; // q[u] = [{id,k},...]

void add(int u,int f){
    cnt[col[u]] += 1; vis[cnt[col[u]]] += 1;
    for(auto v : g[u]){
        if(v == f || v == flag) continue;
        add(v,u);
    }
}

void del(int u,int f){
    vis[cnt[col[u]]] -= 1; cnt[col[u]] -= 1;
    for(auto v : g[u]){
        if(v == f || v == flag) continue;
        del(v,u);
    }
}

void dfs(int u,int f,bool keep){
    for(auto v : g[u]){
        if(v == f || v == son[u]) continue;
        dfs(v,u,false);
    }
    if(son[u]){
        dfs(son[u],u,true);
        flag = son[u];
    }
    add(u,f);
    for(auto [id,k] : q[u]) ans[id] = vis[k];
    flag = 0;
    if(!keep) del(u,f);
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>col[i];
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }
    for(int i=1;i<=m;i++){
        int u,k; cin>>u>>k;
        q[u].push_back({i,k});
    }
    dfs_son(1,0);    
    dfs(1,0,false);
    for(int i=1;i<=m;i++) cout << ans[i] << "\n";
    return 0;
}

/**
 * 1.先遍历 u 的轻（非重）儿子，并计算答案，但 不保留遍历后它对 ans 的影响；
 * 2.遍历它的重儿子，保留它对 ans 的影响；
 * 3.再次遍历 u 的轻儿子的子树结点，加入这些结点的贡献，以得到 u 的答案。
 */