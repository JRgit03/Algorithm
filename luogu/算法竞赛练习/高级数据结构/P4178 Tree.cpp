#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e4 + 10;
int n,k,ans;
vector<pair<int,int>> g[maxn];

bool vis[maxn];
int rt,sum,siz[maxn],f[maxn];

void getrt(int u,int fa){
    siz[u] = 1; f[u] = 0;
    for(auto [v,w] : g[u]){
        if(v == fa || vis[v]) continue;
        getrt(v,u);
        siz[u] += siz[v];
        if(siz[v] > f[u]) f[u] = siz[v];
    }
    f[u] = max(f[u], sum-siz[u]);
    if(f[u] < f[rt]) rt = u;
}

int dist[maxn];
int tmp[maxn],cnt;

void getdist(int u,int fa){
    tmp[cnt++] = u;
    for(auto [v,w] : g[u]){
        if(v == fa || vis[v]) continue;
        dist[v] = dist[u] + w;
        getdist(v,u);
    }
}

// 计算经过点u的路径之和 <= k 
int calc(int u,int val){
    cnt = 0;
    dist[u] = 0;
    getdist(u,0);
    sort(tmp,tmp+cnt,[&](auto i,auto j){ // i j 为 tmp的元素 ！ 无需再使用 tmp[i] 
       return dist[i] < dist[j]; 
    });
    int l = 0, r = cnt - 1 , res = 0;
    while(l<r){
        if(dist[tmp[l]] + dist[tmp[r]] <= k - val) res += r - l, l++;
        else r--;
    }
    return res;
}

// 统计以u为根的路径长为k 在子树v中可能会有不合法路径 即可能是同一子树下的路径
// 去除 以v为根的路径长度为k - 2 * edge(u,v)
void divide(int u){
    // cout << "重心：" << u << "\n";
    vis[u] = true;
    ans += calc(u,0);
    for(auto [v,w] : g[u]){
        if(vis[v]) continue;
        ans -= calc(v,2*w);
        f[rt=0]=sum=siz[v];
        getrt(v,0);
        getrt(rt,0);
        divide(rt);
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w}); g[v].push_back({u,w});
    }
    cin>>k;
    f[rt=0]=sum=n;    
    getrt(1,0);
    getrt(rt,0);
    divide(rt);
    cout << ans << "\n";
    return 0;
}
