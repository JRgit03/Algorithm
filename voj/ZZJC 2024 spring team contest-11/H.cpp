#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
const int N = 1e5 + 10;

int a[N],b[N];

struct Node{
    int l,r;
    int sum;  
    int lazy; 
}tr[N*4];

void pushdown(int u){ 
    auto &root = tr[u] , &left = tr[u<<1] , &right = tr[u<<1|1];
    if(root.lazy){
        left.sum += 1LL * (left.r-left.l+1) * root.lazy , left.lazy += root.lazy;
        right.sum += 1LL * (right.r-right.l+1) * root.lazy , right.lazy += root.lazy;
        root.lazy = 0; 
    }
}

void pushup(int u){ 
    tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum; 
}

void build(int u,int l,int r){
    if(l == r) tr[u] = {l,r,b[r],0}; 
    else{
        tr[u] = {l,r,0,0};
        int mid = l + r >> 1;
        build(u<<1,l,mid) , build(u<<1|1,mid+1,r);
        pushup(u); 
    }
}

void modify(int u,int l,int r,int d){
    if(tr[u].l >= l && tr[u].r <= r){
        tr[u].sum += 1LL * (tr[u].r - tr[u].l + 1) * d;
        tr[u].lazy += d;
    }else{
        pushdown(u); 
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify(u<<1,l,r,d);
        if(r >  mid) modify(u<<1|1,l,r,d);
        pushup(u);
    }
}

int query(int u,int l,int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    pushdown(u); 
    int mid = tr[u].l + tr[u].r >> 1;
    int sum = 0;
    if(l <= mid) sum += query(u<<1,l,r);
    if(r >  mid) sum += query(u<<1|1,l,r);
    return sum;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////


struct Node2{
    int l,r,v;
}tr2[N*4];

void pushup2(int u){ 
    tr2[u].v = max(0LL, tr2[u<<1].v) + max(0LL, tr2[u<<1 | 1].v); 
}

void build2(int u,int l,int r){
    tr2[u] = {l,r,0};
    if(l==r) {
        tr2[u].v = b[l];
        return; 
    }
    int mid = l + r >> 1;
    build2(u<<1,l,mid) , build2(u<<1|1,mid+1,r);
    pushup2(u);
}

int query2(int u,int l,int r){
    if(tr2[u].l>=l&&tr2[u].r<=r) return max(0LL, tr2[u].v);

    int mid = tr2[u].l + tr2[u].r >> 1;
    int v = 0;
    if(l<=mid) v += max(0LL, query2(u<<1,l,r));
    if(r>mid) v += max(0LL, query2(u<<1|1,l,r));

    return v;
}

void modify2(int u,int x,int v){
    if(tr2[u].l==x&&tr2[u].r==x) tr2[u].v += v;
    else{
        int mid = tr2[u].l + tr2[u].r >> 1;
        if(x<=mid) modify2(u<<1,x,v);
        else modify2(u<<1|1,x,v);
        pushup2(u);
    }
}

void solve(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        b[i] = a[i] - a[i-1];
    }
    build(1,1,n); build2(1,1,n);
    while(m--){
        int op,l,r; cin>>op>>l>>r;
        if(op == 1){
            int k; cin>>k;
            
            modify(1,l,l,k); 
            if(r+1<=n) modify(1,r+1,r+1,-k); 

            modify2(1,l,k); 
            if(r+1<=n) modify2(1,r+1,-k); 
        }else{
            int ans = query(1,1,l);
            if(l+1 <= r) ans += query2(1, l+1, r);
            cout << ans << "\n";
        }
    }
}

signed main(){
    IOS;
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
