/**
 * https://www.luogu.com.cn/problem/P3372
 */
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
int n,m;
int w[N];

struct Node{
    int l,r;
    ll sum;  // sum - 区间和
    ll lazy; // lazy - 懒标记,延迟修改 tr[u].lazy 表示以u为根节点的树中节点均需要下传lazy    
}tr[N*4];

void pushdown(int u){ //下传懒标记
    auto &root = tr[u] , &left = tr[u<<1] , &right = tr[u<<1|1];
    if(root.lazy){
        left.sum += 1LL * (left.r-left.l+1) * root.lazy , left.lazy += root.lazy;
        right.sum += 1LL * (right.r-right.l+1) * root.lazy , right.lazy += root.lazy;
        root.lazy = 0; //清空懒标记
    }
}

void pushup(int u){ //由子节点信息来更新父节点信息
    tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum; //注意这里是等号！
}

void build(int u,int l,int r){
    if(l == r) tr[u] = {l,r,w[r],0}; //叶子节点
    else{
        tr[u] = {l,r,0,0};
        int mid = l + r >> 1;
        build(u<<1,l,mid) , build(u<<1|1,mid+1,r);
        pushup(u); //非叶子节点
    }
}

void modify(int u,int l,int r,int d){
    if(tr[u].l >= l && tr[u].r <= r){
        tr[u].sum += 1LL * (tr[u].r - tr[u].l + 1) * d;
        tr[u].lazy += d;
    }else{
        pushdown(u); //pushdown保证了递归路径上一定不存在懒标记 及时处理懒标记
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify(u<<1,l,r,d);
        if(r >  mid) modify(u<<1|1,l,r,d);
        pushup(u);  //pushup保证了递归树的叶节点的改变对父节点的影响能够及时修正
    }
}

ll query(int u,int l,int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    pushdown(u); //及时更新之前未更新的子区间
    int mid = tr[u].l + tr[u].r >> 1;
    ll sum = 0;
    if(l <= mid) sum += query(u<<1,l,r);
    if(r >  mid) sum += query(u<<1|1,l,r);
    return sum;
}

int main(){
    IOS;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i];
    build(1,1,n);
    for(int i=0;i<m;i++){
        int op,l,r,d; cin>>op>>l>>r;
        if(op == 1){
            cin>>d; modify(1,l,r,d);
        }else{
            cout << query(1,l,r) << "\n";
        }
    }
    return 0;
}
