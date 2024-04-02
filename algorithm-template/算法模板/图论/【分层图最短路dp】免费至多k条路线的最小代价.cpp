/**
 * 题意：给定n点，m条边，k次免费访问边，求s到t的最小代价
 *  n<=1e4, m<=5e4, k<=10 
 */
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 10, M = 5e4 + 10, K = 11;
int n,m,k;
int s,t;
int st[N][K];
// dist[i,j]表示到达点i使用了j次免费边的最小代价
int dist[N][K]; 
vector<pair<int,int>> g[N];

struct Node{
    int u,w,cnt;
    Node(){}
    Node(int u,int w,int cnt) : u(u), w(w), cnt(cnt) {}
    bool operator < (const Node& o) const {
        return w > o.w;
    }
}; 

void dij(int s){
    memset(st, 0, sizeof st);
    memset(dist, 0x3f, sizeof dist);
    dist[s][0] = 0;
    priority_queue<Node>  heap;
    heap.push({s,0,0});
    while(heap.size()){
        int u = heap.top().u, cnt = heap.top().cnt; heap.pop();
        if(st[u][cnt]) continue;
        st[u][cnt] = 1;

        for(auto [v,w] : g[u]){
            if(cnt < k && dist[v][cnt + 1] > dist[u][cnt]){
                dist[v][cnt + 1] = dist[u][cnt];
                heap.push({v,dist[v][cnt+1],cnt+1});
            }
            if(dist[v][cnt] > dist[u][cnt] + w){
                dist[v][cnt] = dist[u][cnt] + w;
                heap.push({v,dist[v][cnt],cnt});
            }
        }
    }
}

void solve(){
    cin>>n>>m>>k;
    cin>>s>>t; s++; t++;
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w; u++; v++;
        g[u].push_back({v,w}); g[v].push_back({u,w});
    }    
    dij(s);
    int ans = 1e18;
    for(int j=0;j<=k;j++) ans = min(ans, dist[t][j]);
    cout << ans << "\n";
}

signed main(){
    solve();
    return 0;
}
