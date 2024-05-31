#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 5e3 + 10;
typedef pair<int,int> PII;
int n,m;
vector<PII> g[N];

int inq[N];
int cnt[N];
int dist[N];
int spfa(){
    memset(dist, 0x3f, sizeof dist);
    for(int i=1;i<=n;i++) g[0].push_back({i, 0});
    dist[0] = 0; cnt[0] = 1;
    queue<int> q; q.push(0); inq[0] = 1;

    while(q.size()){
        int u = q.front(); q.pop(); inq[u] = 0;

        for(auto &[v, w] : g[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1; 
                // if(cnt[v] > n + 1) return 1; // n个点判负环和n+1比较, 此处加了虚拟原点0因此一共有n+1个点需要和n+2比较
                if(cnt[v] > n + 10) return 1;  // 判负环开多点包对

                if(!inq[v]){
                    q.push(v); inq[v] = 1;
                }
            }
        }
    }

    return 0;
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        g[v].push_back({u, w});
    }
    if(spfa()) cout << "NO" << "\n";
    else for(int i=1;i<=n;i++) cout << dist[i] << " ";
}

signed main(){
    IOS;
    solve();
    return 0;
}
