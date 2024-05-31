#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e5 + 10, INF = 0x3f3f3f3f3f3f3f3f;
int n,m;
int a[N];

struct Node{
    int l,r,v;
}tr[N << 2];

void pushup(int u){
    tr[u].v = max(tr[u<<1].v, tr[u<<1|1].v);
}

void build(int u,int l,int r){
    if(l == r) tr[u] = {l, r, a[r]};
    else{
        tr[u] = {l,r,0};
        int mid = (l + r) >> 1;
        build(u<<1,l,mid); build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

int query(int u,int l,int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].v;
    else{
        int mid = (tr[u].l + tr[u].r) >> 1;
        int v = -INF;
        if(l <= mid) v = query(u<<1, l, r);
        if(r > mid) v = max(v, query(u<<1|1, l, r));
        return v;
    }
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1, 1, n);
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
