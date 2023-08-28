#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
int n,m,Mod;
int w[N];

struct Node{
    int l,r;
    ll sum,add,mul;
}tr[N*4];

void pushup(int u){
    tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum;
}

void eval(Node &t,int mul,int add){
    t.sum = t.sum * mul + (t.r - t.l + 1) * add;
    t.mul = t.mul * mul;
    t.add = t.add * mul + add;
}

void pushdown(int u){
    eval(tr[u<<1],tr[u].mul,tr[u].add);
    eval(tr[u<<1|1],tr[u].mul,tr[u].add);
    tr[u].mul = 1 , tr[u].add = 0;
}

void build(int u,int l,int r){
    if(l == r) tr[u] = {l,r,w[r],0,1};
    else{
        int mid = l + r >> 1;
        if(l <= mid) build(u<<1,l,mid);
        if(r >  mid) build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(int u,int l,int r,int mul,int add){
    if(tr[u].l >= l && tr[u].r <= r) eval(tr[u],mul,add);
    else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify(u<<1,l,r,mul,add);
        if(r >  mid) modify(u<<1|1,l,r,mul,add);
        pushup(u);
    }
}

ll query(int u,int l,int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    else{
        pushdown(u);
        ll sum = 0;
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) sum += query(u<<1,l,r);
        if(r >  mid) sum += query(u<<1|1,l,r);
        return sum;
    }
}

int main(){
    IOS;
    cin>>n>>m>>Mod;
    for(int i=1;i<=n;i++) cin>>w[i];
    build(1,1,n);
    for(int i=0;i<m;i++){
        int op,l,r,d; cin>>op>>l>>r;
        if(op == 1){
            cin>>d; modify(1,l,r,d,0);
        }
        else if(op == 2) {
            cin>>d; modify(1,l,r,1,d);
        }
        else if(op == 3) {
            cout << query(1,l,r) << "\n";
        }
    }
    return 0;
}
