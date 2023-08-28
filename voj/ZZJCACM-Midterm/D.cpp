#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10 , INF = 0x3f3f3f3f , Mod = 1e5 + 3;
typedef pair<int,int> PII;
int n,m,st=1;
int dist[N],cnt[N];
bool vis[N];
vector<PII> h[N];

void dij(){
    memset(dist,0x3f,sizeof dist);
    dist[st] = 0;
    cnt[st] = 1;
    priority_queue<PII,vector<PII>,greater<PII> > heap;
    heap.push({0,st});
    while(heap.size()){
        auto [distance , u] = heap.top(); heap.pop();
        
        if(vis[u]) continue;
        vis[u] = true;
        
        for(auto [v,w] : h[u]){
            if(dist[v] > distance + w){
                dist[v] = distance + w;
                cnt[v] = cnt[u];
                heap.push({dist[v],v});
            }else if(dist[v] == distance + w){
                cnt[v] = (cnt[v] + cnt[u]) % Mod;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m;
    while(m--){
        int u,v;cin>>u>>v;
        h[u].push_back({v,1}) , h[v].push_back({u,1});
    }
    dij();
    for(int i=1;i<=n;i++) cout << cnt[i] << "\n";
    return 0;
}
