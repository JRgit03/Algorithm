#include <bits/stdc++.h>
#define ONLINE_JUDGE
#define int long long
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10, INF = 0x3f3f3f3f3f3f3f3f , maxdist = 1e6 + 10;
int n,k,ans = INF;
int rt;
vector<pair<int,int>> g[maxn];

bool vis[maxn];
int f[maxn],siz[maxn],sum;

void getrt(int u,int fa){
    siz[u] = 1, f[u] = 0;
    for(auto [v,w] : g[u]){
        if(v == fa || vis[v]) continue;
        getrt(v,u);
        siz[u] += siz[v];
        if(siz[v] > f[u]) f[u] = siz[v];
    }
    f[u] = max(f[u],sum-siz[u]);
    if(f[u] < f[rt]) rt = u;
}

int judge[maxdist]; // judge[i] 表示记录为i到rt的最短边数
int dist[maxn][2]; // dist[i][0] 边权 dist[i][1] 边数
int cnt,tmp[maxn]; // tmp 当前子树遍历到的点

void getdist(int u,int fa){
    tmp[cnt++] = u;
    for(auto [v,w] : g[u]){
        if(v == fa || vis[v]) continue;
        dist[v][0] = dist[u][0] + w;
        dist[v][1] = dist[u][1] + 1;
        getdist(v,u);
    }
}

int que[maxn],hh,tt;

void calc(int u){ //计算经过节点u的路径 子树
    hh = 0, tt = -1;
    for(auto [v,w] : g[u]){
        if(vis[v]) continue;
        cnt = 0;
        dist[v][0] = w; dist[v][1] = 1;
        getdist(v,u);
        for(int j=0;j<cnt;j++){
            if(k >= dist[tmp[j]][0]){
                ans = min(ans,dist[tmp[j]][1]+judge[k-dist[tmp[j]][0]]);
            }
        }
        for(int j=0;j<cnt;j++){
            if(dist[tmp[j]][0] > 1000000) continue;
            que[++tt] = tmp[j];
            judge[dist[tmp[j]][0]] = min(judge[dist[tmp[j]][0]],dist[tmp[j]][1]);
        }
    }
    while(hh<=tt){
        judge[dist[que[hh]][0]] = INF;
        hh++;
    }
}

void divide(int u){
    vis[u] = true; judge[0] = 0;
    calc(u);
    for(auto [v,w] : g[u]){
        if(vis[v]) continue;
        f[rt=0]=sum=siz[v];
        getrt(v,u);
        getrt(rt,0);
        divide(rt);
    }
}

signed main(){
    #ifndef ONLINE_JUDGE
        freopen("E:/in.txt","r",stdin);
    #endif
    cin>>n>>k;
    for(int i=1;i<=1000000;i++) judge[i] = INF;
    for(int i=0;i<n-1;i++){
        int u,v,w; cin>>u>>v>>w; u++,v++;
        g[u].push_back({v,w}); g[v].push_back({u,w});
    }
    f[rt=0]=sum=n;
    getrt(1,0);
    getrt(rt,0);
    divide(rt);
    cout << (ans == INF ? -1 : ans) << "\n";
    return 0;
}
