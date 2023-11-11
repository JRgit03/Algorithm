#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long ll;
int n,m,r,mod;
int v[maxn],w[maxn]; // v:节点值 w:dfs序下的节点值

vector<int> g[maxn];

struct Node{
    int l,r;
    ll sum;  // sum - 区间和
    ll lazy; // lazy - 懒标记,延迟修改 tr[u].lazy 表示以u为根节点的树中节点均需要下传lazy    
}tr[maxn*4];

void pushdown(int u){ //下传懒标记
    auto &root = tr[u] , &left = tr[u<<1] , &right = tr[u<<1|1];
    if(root.lazy){
        left.sum += 1LL * (left.r-left.l+1) * root.lazy , left.lazy += root.lazy;
        left.sum %= mod;
        right.sum += 1LL * (right.r-right.l+1) * root.lazy , right.lazy += root.lazy;
        right.sum %= mod;
        root.lazy = 0; //清空懒标记
    }
}

void pushup(int u){ //由子节点信息来更新父节点信息
    tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum; //注意这里是等号！
}

void build(int u,int l,int r){
    if(l == r) tr[u] = {l,r,w[r],0}; //叶子节点
    else{
        tr[u] = {l,r,0,0};
        int mid = l + r >> 1;
        build(u<<1,l,mid) , build(u<<1|1,mid+1,r);
        pushup(u); //非叶子节点
    }
}

void update(int u,int l,int r,int d){
    if(tr[u].l >= l && tr[u].r <= r){
        tr[u].sum += 1LL * (tr[u].r - tr[u].l + 1) * d;
        tr[u].sum %= mod;
        tr[u].lazy += d;
        tr[u].lazy %= mod;
    }else{
        pushdown(u); //pushdown保证了递归路径上一定不存在懒标记 及时处理懒标记
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) update(u<<1,l,r,d);
        if(r >  mid) update(u<<1|1,l,r,d);
        pushup(u);  //pushup保证了递归树的叶节点的改变对父节点的影响能够及时修正
    }
}

ll query(int u,int l,int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum % mod;
    pushdown(u); //及时更新之前未更新的子区间
    int mid = tr[u].l + tr[u].r >> 1;
    ll sum = 0;
    if(l <= mid) sum = (sum + query(u<<1,l,r)) % mod;
    if(r >  mid) sum = (sum + query(u<<1|1,l,r)) % mod;
    return sum ;
}

int fa[maxn]; // fa[x] 节点x的父节点
int dep[maxn]; // dep[x] 节点x的深度
int siz[maxn]; // siz[x] 节点x为根的子树上节点数量
int son[maxn]; // son[x] 非叶子节点x的重儿子：节点x的最大的儿子

void dfs1(int u,int f){
    fa[u] = f;
    dep[u] = dep[f] + 1;
    siz[u] = 1;
    int maxsize = -1;
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
    w[timestamp] = v[u];
    if(!son[u]) return; //不存在重儿子
    dfs2(son[u],t); // 先DFS重儿子 所有重儿子的链头都是t
    for(auto v : g[u]){ // 再DFS轻儿子
        if(v == fa[u] || v == son[u]) continue; // 当前v为father 或者 重儿子(已处理) 跳过 
        dfs2(v,v); // 定理：一条重链都是以轻儿子为链头 特殊 根节点的轻儿子就是自己
    }
} 

void update_range(int x,int y,int z){
    z %= mod;
    while(top[x] != top[y]){ // 不同重链
        if(dep[top[x]] < dep[top[y]]) swap(x,y); // 优先更新深度大的重链内部
        update(1,dfn[top[x]],dfn[x],z); // l <= r
        x = fa[top[x]];
    }
    if(dep[x] > dep[y]) swap(x,y);
    update(1,dfn[x],dfn[y],z);
}

int query_range(int x,int y){
    int ans = 0;
    while(top[x] != top[y]){ // 不同重链
        if(dep[top[x]] < dep[top[y]]) swap(x,y); // 优先更新深度大的重链内部
        ans += query(1,dfn[top[x]],dfn[x]);
        ans %= mod;
        x = fa[top[x]];
    }
    if(dep[x] > dep[y]) swap(x,y);
    ans += query(1,dfn[x],dfn[y]);
    ans %= mod;
    return ans;
}

void update_tree(int x,int z){
    z %= mod;
    update(1,dfn[x],dfn[x]+siz[x]-1,z);
}

int query_tree(int x){
    return query(1,dfn[x],dfn[x]+siz[x]-1);    
}

int main(){
    cin>>n>>m>>r>>mod;
    for(int i=1;i<=n;i++) cin>>v[i],v[i]%=mod;
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }        
    dfs1(r,r);
    dfs2(r,r);
    build(1,1,n); // 根据dfn序建立树 将树上操作 -> 区间操作
    while(m--){
        int op,x,y,z; cin>>op;
        if(op == 1){
            cin>>x>>y>>z;
            update_range(x,y,z);
        }else if(op == 2){
            cin>>x>>y;
            cout << query_range(x,y) << "\n";
        }else if(op == 3){
            cin>>x>>z;
            update_tree(x,z);
        }else{
            cin>>x;
            cout << query_tree(x) << "\n";
        }
    }
    return 0;
}
