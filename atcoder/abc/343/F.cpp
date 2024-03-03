#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,q;

int a[N];

struct Node{
    int l,r;
    int max1,max2;
    int cnt1,cnt2;
}tr[N * 4];

void calc(Node &root, Node &left, Node &right){
    int m1 = max({left.max1, left.max2, right.max1, right.max2});
    int m2 = -1; 
    if(left.max1 != m1) m2 = max(m2, left.max1);
    if(left.max2 != m1) m2 = max(m2, left.max2);
    if(right.max1 != m1) m2 = max(m2, right.max1);
    if(right.max2 != m1) m2 = max(m2, right.max2);
    // root = {m1, m2, 0, 0};
    root.max1 = m1, root.max2 = m2, root.cnt1 = root.cnt2 = 0;
    if(root.max1 == left.max1) root.cnt1  += left.cnt1;
    if(root.max1 == left.max2) root.cnt1  += left.cnt2;
    if(root.max1 == right.max1) root.cnt1  += right.cnt1;
    if(root.max1 == right.max2) root.cnt1  += right.cnt2;
    if(root.max2 == left.max1) root.cnt2  += left.cnt1;
    if(root.max2 == left.max2) root.cnt2  += left.cnt2;
    if(root.max2 == right.max1) root.cnt2  += right.cnt1;
    if(root.max2 == right.max2) root.cnt2  += right.cnt2;
}

Node calc2(Node left, Node right){
    int m1 = max({left.max1, left.max2, right.max1, right.max2});
    int m2 = -1; 
    if(left.max1 != m1) m2 = max(m2, left.max1);
    if(left.max2 != m1) m2 = max(m2, left.max2);
    if(right.max1 != m1) m2 = max(m2, right.max1);
    if(right.max2 != m1) m2 = max(m2, right.max2);
    Node root = {-1,-1,m1,m2,0,0};
    if(root.max1 == left.max1) root.cnt1  += left.cnt1;
    if(root.max1 == left.max2) root.cnt1  += left.cnt2;
    if(root.max1 == right.max1) root.cnt1  += right.cnt1;
    if(root.max1 == right.max2) root.cnt1  += right.cnt2;
    if(root.max2 == left.max1) root.cnt2  += left.cnt1;
    if(root.max2 == left.max2) root.cnt2  += left.cnt2;
    if(root.max2 == right.max1) root.cnt2  += right.cnt1;
    if(root.max2 == right.max2) root.cnt2  += right.cnt2;
    return root;
}

max()

void pushup(int u){
    calc(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u,int l,int r){

    if(l == r) tr[u] = {l,r,a[r],-1,1,0}; 
    else{
        tr[u] = {l,r,-1,-1,0,0};
        int mid = l + r >> 1;
        build(u<<1,l,mid) , build(u<<1|1,mid+1,r);
        pushup(u); 
    }
}

void modify(int u,int x,int v){
	// cerr << u << " " << tr[u].l << " " << tr[u].r << "\n";
    if(tr[u].l==x&&tr[u].r==x) {
    	tr[u].max1 = v, tr[u].max2 = -1;
    	tr[u].cnt1 = 1, tr[u].cnt2 = 0;
    }else{
        int mid = (tr[u].l + tr[u].r) >> 1;
        if(x<=mid) modify(u<<1,x,v);
        else modify(u<<1|1,x,v);
        pushup(u);
    }
}

Node query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r) return tr[u];

    int mid = tr[u].l + tr[u].r >> 1;

    Node t = {-1,-1,0,0};
    if(l<=mid) t = query(u<<1,l,r);
    if(r>mid) t = calc2(t, query(u<<1|1,l,r));

    return t;
}

int main(){
    scanf("%d%d", &n, &q);
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    build(1,1,n);
    while(q--){
        int op,l,r; cin>>op>>l>>r; 
        if(op == 1) modify(1,l,r);
        else printf("%d\n", query(1,l,r).cnt2 );
    }
    return 0;
}
