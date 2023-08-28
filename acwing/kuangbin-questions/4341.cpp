#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 1e4 + 10;
int n,m;
int res;
bool st[N];

struct Node{
    int l,r;
    int val,lazy;
}tr[N*16];

void build(int u,int l,int r){
    if(l==r) tr[u] = {l,r,0,0};
    else{
        tr[u] = {l,r,0,0};
        int mid = l + r >> 1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    }
}

void pushdown(int u){
    auto &root = tr[u] , &left = tr[u<<1] , &right = tr[u<<1|1];
    if(root.lazy){
        left.val = left.lazy = root.lazy , right.val = right.lazy = root.lazy;
        root.lazy = 0;
    }
}

void modify(int u,int l,int r,int d){
    if(tr[u].l >= l && tr[u].r <= r){
        tr[u].val = d , tr[u].lazy = d;
    }else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l<=mid) modify(u<<1,l,r,d);
        if(r>mid) modify(u<<1|1,l,r,d);
    }
}

void query(int u,int l,int r){
    if(tr[u].l == tr[u].r) {
        if(tr[u].val && !st[tr[u].val]){
            res++;
            st[tr[u].val] = true;
        }
        return;
    }

    pushdown(u);

    int mid = tr[u].l + tr[u].r >> 1;
    if(l<=mid) query(u<<1,l,r);
    if(r>mid)  query(u<<1|1,l,r);

    return;
}

vector<int> alls;

int find(int x){
    int l = 0 , r = alls.size() - 1;
    while(l<r){
        int mid = l + r >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid+1;
    }
    return r+1;
}

void solve(){
    cin>>n;
    alls.clear();
    memset(st,false,sizeof st);
    res=0;

    vector<pair<int,int> > vec(n);

    for(int i=0;i<n;i++){
        int l,r;cin>>l>>r; 
        alls.push_back(l);   
        alls.push_back(l-1);
        alls.push_back(r);
        alls.push_back(r-1);
        vec[i] = {l,r};
    }
                             
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());

    build(1,1,alls.size());

    for(int i=1;i<=n;i++){
        auto [l,r] = vec[i-1];
        l = find(l) , r = find(r);
        modify(1,l,r,i);
    }
    
    query(1,1,alls.size());

    cout << res << "\n";
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
