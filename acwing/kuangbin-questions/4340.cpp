#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,m;
int w[N];

inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

struct Node{
    int l,r;
    int val;
}tr[N*4];

void pushup(int u){
    tr[u].val = max(tr[u<<1].val,tr[u<<1|1].val);
}

void build(int u,int l,int r){
    if(l==r) tr[u] = {l,r,w[r]};
    else{
        tr[u] = {l,r};
        int mid = l+r >> 1;
        build(u<<1,l,mid) , build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

void modify(int u,int k,int x){ //单点修改
    if(tr[u].l == k && tr[u].r == k){
        tr[u].val = x;
    }else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(k<=mid) modify(u<<1,k,x);
        if(k>mid) modify(u<<1|1,k,x);
        pushup(u); 
    }
}

int query(int u,int l,int r){
    if(tr[u].l>=l && tr[u].r<=r) return tr[u].val;
    
    int mid = tr[u].l + tr[u].r >> 1;
    int res = 0;
    if(l<=mid) res = query(u<<1,l,r);
    if(r>mid)  res = max(res,query(u<<1|1,l,r));
    
    return res;
}

int main(){
    while(~scanf("%d %d",&n,&m)){
        for(int i=1;i<=n;i++) w[i]=read();
        build(1,1,n);  
        for(int i=0;i<m;i++){
            char op;int a,b;scanf("%c",&op);a=read(),b=read();
            if(op=='Q') printf("%d\n",query(1,a,b));
            else if(op=='U') modify(1,a,b);
        }     
    }
    return 0;
}
