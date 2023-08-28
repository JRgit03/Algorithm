#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int p[N],sz[N];

int idx;
unordered_map<int,int> mp;

int getid(int x){
    if(mp[x]) return mp[x];
    mp[x] = ++idx; return idx;
}

inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

void write(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
    return;
}

int find(int x){
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}

void merge(int a,int b){
    int pa = find(a) , pb = find(b);
    if(pa!=pb){
        p[pa] = pb;
        sz[pb] += sz[pa];
    }
}

void solve(){
    int n;n=read();
    idx=0; mp.clear();
    for(int i=1;i<=n;i++)p[i]=i,sz[i]=1;
    for(int i=1;i<=n;i++){
        int a,b;a=read();b=read();
        a=getid(a),b=getid(b);
        merge(a,b);
    }
    int maxx = -1;
    for(int i=1;i<=idx;i++){
        if(find(i)==p[i] && sz[i] > maxx)
            maxx = sz[i];
    }
    write(maxx),puts("");
}

int main(){
    int t;t=read();
    while(t--)solve();
    return 0;
}
