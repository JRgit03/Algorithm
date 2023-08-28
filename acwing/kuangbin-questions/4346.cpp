#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 1e5 + 10;
int n,m,q,T;
int dfn[N],dfr[N],timestamp; //dfs序 
bool notroot[N];

vector<int> h[N];

void init(){
    timestamp = 0;
    for(int i=1;i<=n;i++) h[i].clear();
    memset(notroot,false,sizeof notroot);
}

void dfs(int u){
    dfn[u] = ++timestamp;
    for(auto v : h[u])
        dfs(v);
    dfr[u] = ++timestamp;
}

struct Node{
    int l,r;
    int val,lazy;
}tr[N*4];

void pushdown(int u){
    auto &root = tr[u] , &left = tr[u<<1] , &right = tr[u<<1|1];
    if(root.lazy!=-1){
        left.val = left.lazy = root.lazy , right.val = right.lazy = root.lazy;
        root.lazy = -1;
    }
}

void build(int u,int l,int r){
    if(l==r) tr[u] = {l,r,-1,-1};
    else{
        tr[u] = {l,r,-1,-1};
        int mid = l + r >> 1;
        build(u<<1,l,mid) , build(u<<1|1,mid+1,r);
    }
}

void modify(int u,int l,int r,int d){
    if(tr[u].l>=l&&tr[u].r<=r) tr[u].val = d , tr[u].lazy = d;
    else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l<=mid) modify(u<<1,l,r,d);
        if(r>mid) modify(u<<1|1,l,r,d);
    }
}

int query(int u,int k){
    if(tr[u].l==tr[u].r) return tr[u].val;
    
    pushdown(u);
    
    int mid = tr[u].l + tr[u].r >> 1;
    if(k<=mid) return query(u<<1,k);
    else return query(u<<1|1,k);
}

void solve(){
    cin>>n;m=n-1;
    init();
    cout << "Case #" << ++T << ":" << "\n";
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        notroot[u] = true;
        h[v].push_back(u);
    }
    int root = 1;
    while(notroot[root])root++;
    dfs(root);
    build(1,1,timestamp);
    cin>>q;
    while(q--){
        char op;int x,y;cin>>op>>x;
        if(op=='C') cout << query(1,dfn[x]) << "\n";//查询x为根子树区间的左端点 or 查询 [dfn[x],dfr[x]] 区间内任意一点均可
        else if(op=='T'){
            cin>>y; modify(1,dfn[x],dfr[x],y);//将以x为根的dfs序列区间的值置为y
        }
    }
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();    
    return 0;
}
