#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;
int n,T;
int w[N];

inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

struct Node{
    int l,r,sum;
}tr[N*4];

void pushup(int u){
    tr[u].sum = tr[u<<1].sum + tr[u<<1|1].sum;
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

void modify(int u,int k,int x){ //单点修改
    if(tr[u].l==k && tr[u].r==k){
        tr[u].sum += x;
    }else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(k<=mid) modify(u<<1,k,x);
        if(k>mid) modify(u<<1|1,k,x);
        pushup(u);
    }
}

int query(int u,int l,int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    
    int mid = tr[u].l + tr[u].r >> 1;
    int sum = 0;
    if(l<=mid) sum += query(u<<1,l,r);
    if(r>mid) sum += query(u<<1|1,l,r);
    return sum;
}

void solve(){
    n=read();printf("Case %d:\n",++T);
    for(int i=1;i<=n;i++)w[i]=read();
    build(1,1,n);
    char op[10];
    while(~scanf("%s",op)){
        if(op[0]=='E')break;
        if(op[0]=='Q'){
            int l,r;l=read(),r=read();
            printf("%d\n",query(1,l,r));
        }else if(op[0]=='S' || op[0]=='A'){
            int k,x;k=read(),x=read();
            if(op[0]=='S')x=-x;
            modify(1,k,x);
        }
    }
}

int main(){
    int t;t=read();
    while(t--)solve();
    return 0;
}
