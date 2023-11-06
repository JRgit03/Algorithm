#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 10;
int n,ans;
int rt,sum;
bool vis[maxn];
int f[maxn],dis[maxn],siz[maxn];
vector<pair<int,int>> g[maxn];

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}

void getrt(int u,int fa){
    siz[u] = 1, f[u] = 0;
    for(auto &[v,w] : g[u]){
        if(v == fa || vis[v]) continue;
        getrt(v,u);
        siz[u] += siz[v];
        if(siz[v] > f[u]) f[u] = siz[v];
    }
    f[u] = max(f[u], sum - siz[u]); 
    if(f[u] < f[rt]) rt = u;
}

int mp[3];
int cnt,tmp[maxn];

void getdis(int u,int fa){
    tmp[cnt++] = u;
    for(auto &[v,w] : g[u]){
        if(v == fa || vis[v]) continue;
        dis[v] = (dis[u] + w) % 3;
        getdis(v,u);
    }
}

int que[maxn],hh,tt;

// 计算经过点u路径的方案
void calc(int u,int fa){
    hh = 0, tt = -1;
    for(auto &[v,w] : g[u]){
        if(v == fa || vis[v]) continue;
        cnt = 0;
        dis[v] = w % 3;
        getdis(v,u);
         for(int j=0;j<cnt;j++)
             ans += mp[(3-dis[tmp[j]])%3];
        for(int j=0;j<cnt;j++){
            que[++tt] = tmp[j];
            mp[dis[tmp[j]]]++;
        }
    }
    while(hh <= tt){
        mp[dis[que[hh]]]--;
        hh++;
    }
}

void divide(int u,int fa){
    vis[u] = true; mp[0] = 1;
    calc(u,fa);
    for(auto &[v,w] : g[u]){
        if(v == fa || vis[v]) continue;
        f[rt=0]=sum=siz[v];
        getrt(v,u);
        getrt(rt,0);
        divide(rt,0);
    }
}

int main(){
    n = read();
    for(int i=0;i<n-1;i++){
        int u,v,w; u = read(); v = read(); w = read(); w %= 3;
        g[u].emplace_back(v,w); g[v].emplace_back(u,w);
    }
    f[rt=0]=sum=n;
    getrt(1,0);
    getrt(rt,0);
    divide(rt,0);
    cout << (ans * 2 + n) / __gcd((ans * 2 + n),n*n) << "/" << n * n / __gcd((ans * 2 + n),n*n) << "\n";
    return 0;
}
