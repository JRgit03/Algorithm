#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10, INF = 1e18, up = 1e6;
int n,L,R;
// dp[b[i]] 表示 完全覆盖dp[L~i]的最小代价
// dp[b[i]] = min{dp[j]} + c[i] (a[i] - 1 <= j <= b[i])
// 需要保证 dp[j] 更新完毕 按右端点排升序 优先处理
int dp[N]; 

struct Node{
    int l,r;
    int v;
}tr[N*4];

void pushup(int u){ 
    tr[u].v = min(tr[u<<1].v , tr[u<<1 | 1].v);
}

void build(int u,int l,int r){
    tr[u] = {l,r};
    if(l==r) {
        if(r == L - 1) tr[u].v = 0;
        else tr[u].v = INF;
        return; 
    }
    int mid = l + r >> 1;
    build(u<<1,l,mid) , build(u<<1|1,mid+1,r);
    pushup(u);
}

int query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r) return tr[u].v;

    int mid = tr[u].l + tr[u].r >> 1;
    int v = INF;
    if(l<=mid) v = query(u<<1,l,r);
    if(r>mid) v = min(v,query(u<<1|1,l,r));

    return v;
}

void modify(int u,int x,int v){
    if(tr[u].l==x&&tr[u].r==x) tr[u].v = v;
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(x<=mid) modify(u<<1,x,v);
        else modify(u<<1|1,x,v);
        pushup(u);
    }
}

void solve(){
    // 保证 L-1的状态合法且数组从1开始 偏移量+2
    cin>>n>>L>>R; L+=2; R+=2;
    vector<array<int,3>> vec(n);
    for(int i=0;i<n;i++){
        int a,b,c; cin>>a>>b>>c; a += 2; b += 2;
        vec[i] = {a,b,c};
    }
    sort(vec.begin(), vec.end(), [&](auto &p, auto &q){
        return p[1] < q[1];
    });
    build(1,1,up);
    for(int i=0;i<n;i++){
        auto [a,b,c] = vec[i];
        int l = max(L-1, a-1), r = b;
        modify(1,b,min(query(1,b,b), query(1,l,r)+c));
    }
    cout << (query(1,R,R) == INF ? -1 : query(1,R,R)) << "\n";
}

signed main(){
    solve();
    return 0;
}
