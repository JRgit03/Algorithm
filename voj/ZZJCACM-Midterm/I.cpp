#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10 , INF = 0x3f3f3f3f , Mod = 1e5 + 3;
typedef pair<int,int> PII;
int n,m,st;
int dist[N];
bool vis[N];
vector<PII> h[N];

void dij(){
    memset(dist,0x3f,sizeof dist);
    dist[st] = 0;
    priority_queue<PII,vector<PII>,greater<PII> > heap;
    heap.push({0,st});
    while(heap.size()){
        auto [distance , u] = heap.top(); heap.pop();
        
        if(vis[u]) continue;
        vis[u] = true;
        
        for(auto [v,w] : h[u]){
            if(dist[v] > distance + w){
                dist[v] = distance + w;
                heap.push({dist[v],v});
            }
        }
    }
}

int main(){
    cin>>n>>m>>st;
    while(m--){
        int u,v,w;cin>>u>>v>>w;
        h[u].push_back({v,w});
    }
    dij();
    for(int i=1;i<=n;i++) cout << dist[i] << " ";
    return 0;
}
