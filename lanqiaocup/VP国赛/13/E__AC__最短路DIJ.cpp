#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e3 + 10;
typedef pair<int,int> PII;
int n,m;
int c[N];
int st[N];
int dist[N]; // dist[u] 表示 达到点u且被隔离的最小代价
vector<PII> g[N];

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w}); g[v].push_back({u,w});
    }
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    dist[1] = 0;
    heap.push({dist[1], 1});
    while(heap.size()){
        auto [distance, u] = heap.top(); heap.pop();
        debug(u, distance);
        if(st[u]) continue;
        st[u] = 1;

        for(auto &[v,w] : g[u]){
            if(dist[v] > dist[u] + w + c[v]){
                dist[v] = dist[u] + w + c[v];
                heap.push({dist[v], v});
            }
        }
    }
    if(n == 1) cout << 0 << "\n";
    else cout << dist[n] - c[n] << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}


/**
 *  赛时版本 dist[u][0/1] dist[u][j] 到达点u状态为j的最少代价 j表示是否继续前进 
 */

// #include <bits/stdc++.h>
// #define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define int long long
// using namespace std;

// int max(int a,int b){return a > b ? a : b;}
// int min(int a,int b){return a < b ? a : b;}

// const int N = 1e3 + 10;
// typedef pair<int,int> PII;
// int n,m;
// int c[N];
// int st[N][2];
// int dist[N][2];
// vector<PII> g[N];

// struct Node{
//     int w,u,t;
    
//     // A < B 返回true B排前面
//     bool operator < (const Node& o) const {
//         if(w != o.w) return w > o.w;
//         if(t != o.t) return t > o.t;
//         return u > o.u;
//     }
// };

// void solve(){
//     cin>>n>>m;
//     for(int i=1;i<=n;i++) cin>>c[i];
//     for(int i=0;i<m;i++){
//         int u,v,w; cin>>u>>v>>w;
//         g[u].push_back({v,w}); g[v].push_back({u,w}); 
//     }
    
//     memset(dist, 0x3f, sizeof dist);
//     priority_queue<Node> heap;
//     dist[1][0] = dist[1][1] = 0;
//     heap.push({dist[1][0], 1, 0});
//     heap.push({dist[1][1], 1, 1});
    
//     while(heap.size()){
//         int distance = heap.top().w, u = heap.top().u, t = heap.top().t; 
//         // cerr << "distance" << " " << distance << "\n";
//         heap.pop();
        
//         if(st[u][t]) continue;
//         st[u][t] = 1;
        
//         if(t == 1){
//             for(auto &item : g[u]){
//                 int v = item.first, w = item.second;
//                 if(dist[v][0] > dist[u][t] + w){
//                     dist[v][0] = dist[u][t] + w;
//                     heap.push({dist[v][0], v, 0});
//                     dist[v][1] = dist[u][t] + w + c[v];
//                     heap.push({dist[v][1], v, 1});
//                 }
//             }
//         }
//     } 
    
//     cout << dist[n][0] << "\n";
// }

// signed main(){
//     solve();
//     return 0;
// }


/*
4 4
5 7 3 4
1 2 4
1 3 5
2 4 3
3 4 5

13
*/
