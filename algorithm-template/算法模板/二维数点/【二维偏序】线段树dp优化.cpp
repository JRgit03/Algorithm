//https://atcoder.jp/contests/abc339/tasks/abc339_e

// 二维偏序
// 一个长度为n的数组a和一个数D，删去若干个数，使得剩余数俩俩差不超过D 问删去个数的最小值
// n <= 5e5, ai <= 5e5, D <= 5e5
// dp[i] = max(dp[j]) + 1 (j < i && |a[i] - a[j]| <= D)
// 朴素O(n^2) ai <= 5e5 考虑线段树优化动态单点修改区间查询最大值
// 从前往后依次处理a[i] 由于ai <= 5e5 线段树叶子节点即可以表示以ai结尾的dp[ai]最大值

#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N];
int dp[N];

struct Node{
    int l,r;
    int v;
}tr[N*4];

void pushup(int u){ 
    tr[u].v = max(tr[u<<1].v , tr[u<<1 | 1].v);
}

void build(int u,int l,int r){
    tr[u] = {l,r};
    if(l==r) return; 
    int mid = l + r >> 1;
    build(u<<1,l,mid) , build(u<<1|1,mid+1,r);
}

int query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r) return tr[u].v;

    int mid = tr[u].l + tr[u].r >> 1;
    int v = 0;
    if(l<=mid) v = query(u<<1,l,r);
    if(r>mid) v = max(v,query(u<<1|1,l,r));

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

int main(){
    int n,d; scanf("%d%d",&n,&d);
    int up = 5e5; for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,up);
    int ans = 0;
    for(int i=1;i<=n;i++){
        int L = max(1,a[i] - d), R = min(up, a[i] + d);
        dp[i] = query(1,L,R) + 1;
        ans = max(ans, dp[i]);
        modify(1,a[i],dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}
