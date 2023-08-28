#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 1e5 + 10;
int n,m,T;
int w[N];

struct Node{
    int l,r;
    int val;
}tr[N*4];

void pushup(int u){
    tr[u].val = tr[u<<1].val + tr[u<<1|1].val;
}

void build(int u,int l,int r){
    if(l==r) tr[u] = {l,r,w[r]};
    else{
        tr[u] = {l,r};
        int mid = l+r>>1;
        build(u<<1,l,mid) , build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(int u,int l,int r){
    if(tr[u].r-tr[u].l+1==tr[u].val) return; //优化

    if(tr[u].l==tr[u].r&&tr[u].l>=l&&tr[u].r<=r) tr[u].val = sqrt(tr[u].val);
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(l<=mid) modify(u<<1,l,r);
        if(r>mid) modify(u<<1|1,l,r);
        pushup(u);
    }
}

int query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r) return tr[u].val;
    
    int sum = 0;
    int mid = tr[u].l + tr[u].r >> 1;
    if(l<=mid) sum = query(u<<1,l,r);
    if(r>mid) sum += query(u<<1|1,l,r);

    return sum;
}

signed main(){
    IOS;
    while(cin>>n){
        cout << "Case #" << ++T << ":" << "\n";
        for(int i=1;i<=n;i++)cin>>w[i];
        build(1,1,n);
        cin>>m;
        while(m--){
            int op,l,r;cin>>op>>l>>r;
            if(l>r)swap(l,r);
            if(!op)modify(1,l,r);
            else cout<<query(1,l,r)<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}
