#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
const int N = 1e5 +10;

int n,m;
int a[N],b[N];

int max(int a,int b){
    return a > b ? a : b;
}

struct Node{
    int l,r;
    int v; // 原差分序列值
    int v2;  // 正数原差分序列值
}tr[N*4];

void pushup(int u){ 
    tr[u].v = tr[u<<1].v + tr[u<<1 | 1].v;
    tr[u].v2 = tr[u<<1].v2 + tr[u<<1 | 1].v2;
}

void build(int u,int l,int r){
    tr[u] = {l,r,0,0};
    if(l==r) {
        tr[u].v = b[l];
        tr[u].v2 = max(0, tr[u].v);
        return; 
    }
    int mid = l + r >> 1;
    build(u<<1,l,mid) , build(u<<1|1,mid+1,r);
    pushup(u);
}

int query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r) return tr[u].v;

    int mid = tr[u].l + tr[u].r >> 1;
    int v = 0;
    if(l<=mid) v += query(u<<1,l,r);
    if(r>mid) v += query(u<<1|1,l,r);

    return v;
}

int query2(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r) return tr[u].v2;

    int mid = tr[u].l + tr[u].r >> 1;
    int v2 = 0;
    if(l<=mid) v2 += query2(u<<1,l,r);
    if(r>mid) v2 += query2(u<<1|1,l,r);

    return v2;
}

void modify(int u,int x,int v){
    if(tr[u].l==x&&tr[u].r==x) {
        tr[u].v += v;
        tr[u].v2 = max(0, tr[u].v);
    }else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(x<=mid) modify(u<<1,x,v);
        else modify(u<<1|1,x,v);
        pushup(u);
    }
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i]; b[i] = a[i] - a[i-1];
    }
    build(1,1,n);
    while(m--){
        int op,l,r; cin>>op>>l>>r;
        if(op == 1){
            int v; cin>>v; 
            modify(1,l,v); 
            if(r+1<=n) modify(1,r+1,-v);
        }else{
            int ans = query(1,1,l);
            if(l+1<=r) ans += query2(1,l+1,r);
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
