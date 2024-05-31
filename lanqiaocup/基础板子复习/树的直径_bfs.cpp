// https://www.luogu.com.cn/problem/SP1437
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e4 + 10, INF = 0x3f3f3f3f3f3f3f3f;
int n;
int dist[N];
vector<int> g[N];

int bfs(int st){
    memset(dist, 0x3f, sizeof dist);
    dist[st] = 0;
    queue<int> q; q.push(st);

    while(q.size()){
        int u = q.front(); q.pop();
        
        for(auto &v : g[u]){
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    int p = 1, maxx = dist[1];
    for(int i=2;i<=n;i++) if(dist[i] > maxx){
        maxx = dist[i], p = i;
    }
    return p;
}

// 两次bfs求直径要求树不存在负权边
void solve(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }
    int a = bfs(1);
    int b = bfs(a);
    cout << dist[b] << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
