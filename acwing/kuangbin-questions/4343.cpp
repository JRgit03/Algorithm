#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 1e4 + 10;
int n;
int st[N];
int cnt[N];

struct Node{
    int l,r;
    int val,lazy;
}tr[N*4];

void pushdown(int u){
    auto &root = tr[u] , &left = tr[u<<1] , &right = tr[u<<1|1];
    if(root.lazy){
        left.val = left.lazy = root.lazy;
        right.val = right.lazy = root.lazy;
        root.lazy = 0;
    }
}

void build(int u,int l,int r){
    if(l==r) tr[u] = {l,r,0,0};
    else{
        tr[u] = {l,r};
        int mid = l+r >> 1;
        build(u<<1,l,mid) , build(u<<1|1,mid+1,r);
    }
}

void modify(int u,int l,int r,int d){
    if(tr[u].l>=l && tr[u].r<=r){
        tr[u].val = tr[u].lazy = d;
    }else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l<=mid) modify(u<<1,l,r,d);
        if(r>mid) modify(u<<1|1,l,r,d);
    }
}

void query(int u,int l,int r){
    //cout << tr[u].l << " " << tr[u].r << "\n";
    if(tr[u].l==tr[u].r){
        st[tr[u].l] = tr[u].val;
    }else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l<=mid) query(u<<1,l,r);
        if(r>mid) query(u<<1|1,l,r);
    }
}

void solve(){
    memset(cnt,0,sizeof cnt);
    build(1,1,8001);
    for(int i=1;i<=n;i++){
        int l,r,d;cin>>l>>r>>d;l++,r++;d++;
        modify(1,l,r-1,d); //每个点表示一段
    }
    query(1,1,8001);
    //for(int i=1;i<=5;i++) cout<<st[i]<<" \n"[i==5];
    for(int i=1;i<=8001;i++){
        if(st[i]){
            cnt[st[i]]++;
            int j = i;
            while(j<=8001&&st[i]==st[j])j++;
            i = j-1;
        }
    }
    for(int i=1;i<=8001;i++)if(cnt[i])cout<<i-1<<" "<<cnt[i]<<"\n";
    cout<<"\n";
}

int main(){
    IOS;
    while(cin>>n)solve();
    return 0;
}
