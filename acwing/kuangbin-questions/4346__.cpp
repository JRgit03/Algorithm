#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 5e4 + 10;
int n,m,T;

struct Node{
    int l,r;
    int val,lazy;
}tr[N*4];

bool notroot[N];
vector<int> h[N];

int in[N],out[N],idx;

void dfs(int u){
    in[u] = ++idx;
    for(auto v : h[u]) 
        dfs(v);
    out[u] = idx;
}

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
    if(tr[u].l>=l&&tr[u].r<=r) tr[u].val = tr[u].lazy = d;
    else{
        pushdown(u);

        int mid = tr[u].l + tr[u].r >> 1;
        if(l<=mid) modify(u<<1,l,r,d);
        if(r>mid) modify(u<<1|1,l,r,d);
    }
}

int query(int u,int k){
    //cout << u << " " << tr[u].l << " " << tr[u].r << "\n";
    if(tr[u].l==tr[u].r) return tr[u].val;
    else{
        pushdown(u);

        int mid = tr[u].l + tr[u].r >> 1;
        if(k<=mid) return query(u<<1,k);
        else return query(u<<1|1,k);
    }
}

void solve(){
    cout << "Case #" << ++T << ":" << "\n";
    cin>>n;
    for(int i=1;i<=n;i++) h[i].clear() , notroot[i] = false;
    for(int i=0;i<n-1;i++){
        int son,fa;cin>>son>>fa;
        h[fa].push_back(son);
        notroot[son] = true;
    }
    int root = 1; while(notroot[root])root++; //cout << root << "\n";
    idx=0;dfs(root); //for(int i=1;i<=n;i++) cout << i << " " << in[i] << " " << out[i] << "\n";
    build(1,1,n);
    cin>>m;
    while(m--){
        char op;int x,y;cin>>op;
        if(op=='T'){
            cin>>x>>y;
            modify(1,in[x],out[x],y);
        }else if(op=='C'){
            cin>>x;
            cout << query(1,in[x]) << "\n";
        }
    }
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
