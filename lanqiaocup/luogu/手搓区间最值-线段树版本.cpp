#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 2e5 + 10, INF = 0x3f3f3f3f;
int n,m;
int a[N];

struct Node{
    int l,r,v;
}tr[N << 2];

void pushup(int u){
    tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}

void build(int u,int l,int r){
    tr[u] = {l,r,0};
    if(l == r){
        tr[u].v = a[r];
        return;
    }else{
        int mid = l + r >> 1;
        if(l <= mid) build(u << 1, l, mid);
        if(r > mid) build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

int query(int u,int l,int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].v;
    else {
        int mid = (tr[u].l + tr[u].r) >> 1;
        int v = -INF;
        if(l <= mid) v = query(u<<1, l, r);
        if(r > mid) v = max(v, query(u<<1|1, l, r));
        return v;
    }
}

void modify(int u,int x,int v){
    if(tr[u].l == x && tr[u].r == x){
        tr[u].v = v;
        return;
    }else{
        int mid = (tr[u].l + tr[u].r) >> 1;
        if(x <= mid) modify(u << 1, x, v);
        else modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    cin>>m;
    while(m--){
        int l,r; cin>>l>>r;
        cout << query(1, l, r) << "\n";
    }
}

signed main(){
    IOS;
    solve();
    return 0;
}
