#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n,m;
int w[N];

struct Node{
    int l,r;
    int sum,add;
}tr[N*4];

void pushup(int u){ // 子节点更新父节点
    tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum;
}

void build(int u,int l,int r){
    if(l==r) tr[u] = {l,r,w[r],0};
    else{
        tr[u] = {l,r};
        int mid = l + r >> 1;
        build(u<<1,l,mid) , build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void pushdown(int u){ // 父节点更新子节点 向下传递懒标记
    auto &root = tr[u] , &left = tr[u<<1] , &right = tr[u<<1|1];
    if(root.add){ 
        left.add += root.add , right.add += root.add;
        left.sum += (left.r-left.l+1) * root.add , right.sum += (right.r-right.l+1) * root.add;
        root.add = 0; // 清除懒标记
    } 
}

void modify(int u,int l,int r,int d){
    if(tr[u].l >= l && tr[u].r <= r){
        tr[u].sum += (tr[u].r - tr[u].l + 1) * d;
        tr[u].add += d; // lazy - tag
    }else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l<=mid) modify(u<<1,l,r,d);
        if(r>mid)  modify(u<<1|1,l,r,d);
        pushup(u);
    }
}

int query(int u,int l,int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    
    pushdown(u);

    int mid = tr[u].l + tr[u].r >> 1;
    int res = 0;
    if(l<=mid) res = query(u<<1,l,r);
    if(r>mid)  res += query(u<<1|1,l,r);

    return res;
}

signed main(){
    IOS;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i];
    build(1,1,n);
    for(int i=0;i<m;i++){
        char op;cin>>op;int l,r;cin>>l>>r;
        if(op=='Q') cout<<query(1,l,r)<<"\n";
        else if(op=='C'){
            int d;cin>>d;modify(1,l,r,d);
        }
    }
    return 0;
}
