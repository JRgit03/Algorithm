#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int n,m,root;
vector<int> g[maxn];

int fa[maxn]; // fa[x] 节点x的父节点
int dep[maxn]; // dep[x] 节点x的深度
int siz[maxn]; // siz[x] 节点x为根的子树上节点数量
int son[maxn]; // son[x] 非叶子节点x的重儿子：节点x的最大的儿子

void dfs1(int u,int f){
    fa[u] = f;
    dep[u] = dep[f] + 1;
    siz[u] = 1;
    int maxsize = -1; // 临时变量 用于判断重儿子
    for(auto v : g[u]){
        if(v == f) continue;
        dfs1(v,u);
        siz[u] += siz[v];
        if(siz[v] > maxsize){
            maxsize = siz[v];
            son[u] = v;
        }
    }
}

int timestamp; // 时间戳
int dfn[maxn]; // dfs序 每个节点的访问顺序
int top[maxn]; // top[x] 节点x所在重链的链头

void dfs2(int u,int t){
    dfn[u] = ++timestamp;
    top[u] = t;
    if(!son[u]) return; //不存在重儿子
    dfs2(son[u],t); // 先DFS重儿子 所有重儿子的链头都是t
    for(auto v : g[u]){ // 再DFS轻儿子
        if(v == fa[u] || v == son[u]) continue; // 当前v为father 或者 重儿子(已处理) 跳过 
        dfs2(v,v); // 定理：一条重链都是以轻儿子为链头 特殊 根节点的轻儿子就是自己
    }
} 

int LCA(int x,int y){
    while(top[x] != top[y]){ // 不在同一条重链上
        if(dep[top[x]] < dep[top[y]]) swap(x,y); 
        x = fa[top[x]]; //让链头更深的往上跳
    }
    // while处理完保证在同一条链上 top[x] == top[y]
    return dep[x] < dep[y] ? x : y;  
}

int main(){
    cin>>n>>m>>root;
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }
    dfs1(root,root);
    dfs2(root,root);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        cout << LCA(u,v) << "\n";
    }
    return 0;
}
