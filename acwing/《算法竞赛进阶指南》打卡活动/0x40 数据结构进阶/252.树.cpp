#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
typedef pair<int,int> PII;
int n,k,ans;

vector<PII> g[maxn];

int rt,sum;
int siz[maxn];
int f[maxn];
int vis[maxn];

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

int tmp[maxn],cnt;
int dist[maxn];

void getdist(int u,int fa){
    tmp[cnt++] = u;
    for(auto [v,w] : g[u]){
        if(v == fa || vis[v]) continue;
        dist[v] = dist[u] + w;
        getdist(v,u);
    }
}

int calc(int u,int val){
    cnt = 0;
    dist[u] = 0;
    getdist(u,0);
    sort(tmp,tmp+cnt,[&](int i,int j){
        return dist[i] < dist[j];
    });
    // cout << "rt: " << u << "\n";
    // for(int i=0;i<cnt;i++) cout << tmp[i] << " " << dist[tmp[i]] << "\n";
    int l = 0, r = cnt - 1, res = 0;
    while(l<r){
        if(dist[tmp[l]] + dist[tmp[r]] <= k - val) res += r - l, l++;
        else r--;
    }
    // cout << "res: " << res << "\n\n";
    return res;
}

void divide(int u){
    vis[u] =  true;
    ans += calc(u,0);
    for(auto [v,w] : g[u]){
        if(vis[v]) continue;
        ans -= calc(v,w*2);
        f[rt=0]=sum=siz[v];
        getrt(v,0);
        getrt(rt,0);
        divide(rt);
    }
}

void solve(){
    ans = 0;
    for(int i=1;i<=n;i++) {
        g[i].clear();
        vis[i] = false;
    }
    for(int i=0;i<n-1;i++){
        int u,v,w; cin>>u>>v>>w; u++,v++;
        g[u].push_back({v,w}); g[v].push_back({u,w});
    }
    f[rt=0]=sum=n;
    getrt(1,0);
    getrt(rt,0);
    divide(rt);
    cout << ans << "\n";
}

int main(){
    while(cin>>n>>k){
        if(!n && !k) break;
        solve();
    }    
    return 0;
}
