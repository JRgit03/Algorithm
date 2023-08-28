#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 1e5 + 10;
int n,m,T;
int res;
struct Node{
    int l,r;
    int val,lazy;
}tr[N*4];

void pushup(int u){
    tr[u].val = tr[u<<1].val + tr[u<<1|1].val;
}

void pushdown(int u){
    auto &root = tr[u] , &left = tr[u<<1] , &right = tr[u<<1|1];
    if(root.lazy){
        left.val = (left.r-left.l+1)*root.lazy , left.lazy = root.lazy;
        right.val = (right.r-right.l+1)*root.lazy , right.lazy = root.lazy;
        root.lazy = 0;
    }
}

void build(int u,int l,int r){
    if(l==r) tr[u] = {l,r,1,0};
    else{
        tr[u] = {l,r};
        int mid = l+r >> 1;
        build(u<<1,l,mid) , build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(int u,int l,int r,int d){ //单点修改  注意是替换~
    if(tr[u].l>=l && tr[u].r<=r){
        tr[u].lazy = d;
        tr[u].val = (tr[u].r-tr[u].l+1)*d;
    }else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l<=mid) modify(u<<1,l,r,d);
        if(r>mid) modify(u<<1|1,l,r,d);
        pushup(u);
    }
}

void query(int u,int l,int r){
    if(tr[u].l==tr[u].r){
        //cout << tr[u].l << " " << tr[u].r << " " << tr[u].val << "\n";
        res += tr[u].val;
    }else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l<=mid) query(u<<1,l,r);
        if(r>mid) query(u<<1|1,l,r);
    }
}

void solve(){
    cin>>n;
    build(1,1,n);
    cin>>m;
    while(m--){
        int l,r,d;cin>>l>>r>>d;
        modify(1,l,r,d);
    }
    res=0;query(1,1,n);
    printf("Case %d: The total value of the hook is %d.\n",++T,res);
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
