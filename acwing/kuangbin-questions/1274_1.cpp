/**
 *  离线线段树
 */
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 5e4 + 10;
typedef pair<int,int> PII;
int n,m;
int w[N];

struct Node{
    int l,r;
    int minn,maxx;
}tr[N*4];

void pushup(int u){
    auto &root = tr[u] , &left = tr[u<<1] , &right = tr[u<<1|1];
    root.minn = min(left.minn,right.minn) , root.maxx = max(left.maxx,right.maxx);
}

void build(int u,int l,int r){
    if(l==r) tr[u] = {l,r,w[r],w[r]};
    else{
    	tr[u] = {l,r};
        int mid = l + r >> 1;
        build(u<<1,l,mid) , build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

int queryMin(int u,int l,int r){
    if(tr[u].l>=l&tr[u].r<=r) return tr[u].minn;
    
    int mid = tr[u].l + tr[u].r >> 1;
    int res = 2e9;
    if(l<=mid) res = queryMin(u<<1,l,r);
    if(r>mid) res = min(res,queryMin(u<<1|1,l,r));

    return res;
}

int queryMax(int u,int l,int r){
    if(tr[u].l>=l&tr[u].r<=r) return tr[u].maxx;
    
    int mid = tr[u].l + tr[u].r >> 1;
    int res = -1;
    if(l<=mid) res = queryMax(u<<1,l,r);
    if(r>mid) res = max(res,queryMax(u<<1|1,l,r));

    return res;
}

int main(){
    IOS;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i];
    build(1,1,n);
    while(m--){
        int l,r;cin>>l>>r;
        cout << queryMax(1,l,r) - queryMin(1,l,r) << "\n";
    }
    return 0;
}
