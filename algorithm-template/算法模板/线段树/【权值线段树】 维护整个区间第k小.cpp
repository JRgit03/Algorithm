/**
 * 链接：https://ac.nowcoder.com/acm/contest/1076/B
    有一个长度为n的序列，序列每个元素取值范围[1, 1e6]，现在有q次操作，每次操作：
    1 k：查询整个序列第 k 大元素（指的是从小到大排序后第 k 个元素）
    2 x y：将下标为x（下标从1开始）的元素值修改为y
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n,q;
int a[maxn];

struct Node{
    int l,r;
    int sum; // sum 维护值域l~r的个数
}tr[maxn<<2];

void pushup(int u){
    tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum;
}

void build(int u,int l,int r){
    if(l == r) tr[u] = {l,r,0};
    else{
        tr[u] = {l,r,0};
        int mid = l + r >> 1;
        build(u<<1,l,mid); 
        build(u<<1|1,mid+1,r);
    }
}

void modify(int u,int pos,int val){
    if(tr[u].l == tr[u].r) tr[u].sum += val;
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(pos <= mid) modify(u<<1,pos,val);
        else modify(u<<1|1,pos,val);
        pushup(u);
    }
}

int kth(int u,int k){
    if(tr[u].l == tr[u].r) return tr[u].r;
    else{
        if(k <= tr[u<<1].sum) return kth(u<<1,k);
        else return kth(u<<1|1,k-tr[u<<1].sum);
    }
}

int main(){
    build(1,1,1'000'000);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        modify(1,a[i],1);
    };
    while(q--){
        int op,k,x,y; cin>>op;
        if(op == 1){
            cin>>k; cout << kth(1,k) << "\n";
        }else{
            cin>>x>>y;
            modify(1,a[x],-1);
            a[x] = y;
            modify(1,a[x],1);
        }
    }
    return 0;
}

/**
 * 权值线段树: 
 * 1.用线段树维护的桶
 * 2.每一个节点保存的是值大小在管辖区间中的个数
 * 3.叶子节点编号 对应值的个数
 * 单点修改 二分查询
*/