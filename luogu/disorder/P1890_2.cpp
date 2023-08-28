#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n,q;
int w[N];

struct Node{ //没有懒标记的线段树 仅 建树 + 查询
    int l,r;
    int val; // [l,r]区间gcd的值
}tr[N*4];

inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int gcd(int a,int b){
    return b ? gcd(b,a%b) : a;
}

void pushup(int u){
    tr[u].val = gcd(tr[u<<1].val , tr[u<<1|1].val);
}

void build(int u,int l,int r){
    if(l==r) tr[u] = {l,r,w[r]};
    else{
        tr[u] = {l,r};
        int mid = l + r >> 1;
        build(u<<1,l,mid) , build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

int query(int u,int l,int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].val;
    
    int mid = tr[u].l + tr[u].r >> 1;
    int res = 0;
    if(l<=mid) res = gcd(res,query(u<<1,l,r));
    if(r>mid) res = gcd(res,query(u<<1|1,l,r));
    return res;
}

int main(){
    n=read(),q=read();
    for(int i=1;i<=n;i++) w[i]=read();
    build(1,1,n);
    while(q--){
        int l,r;l=read(),r=read();
        printf("%d\n",query(1,l,r));
    }
    return 0;
}
