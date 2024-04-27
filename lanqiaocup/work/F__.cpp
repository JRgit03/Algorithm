#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){ return a > b ? a : b;}
int min(int a,int b){ return a < b ? a : b;}

const int N = 5e3 + 10, INF = 0x3f3f3f3f;
int n,m;
int c[N];
int vis[N];
int dist[N];
int dist2[N];

int f[N];
vector<int> g[N]; 
vector<int> h[N];

int calc(int s,int t){
    int ans = INF;

    for(int i=1;i<=n;i++) {
        dist[i] = dist2[i] = INF; 
        f[i] = -1;
    }
    queue<int> q;
    dist[t] = 0;
    q.push(t);
    
    while(q.size()){
        int u = q.front(); q.pop();
        if(f[c[u]] == -1){
            f[c[u]] = dist[u];
        }
        
        for(auto v : g[u]){
            if(dist[v] != INF) continue;
            dist[v] = dist[u] + 1;
            q.push(v); 
        }
    } 

    typedef pair<int,int> PII; 
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    for(int i=1;i<=n;i++) vis[i] = 0;
    dist2[s] = 0;
    heap.push({dist2[s], s});
    while(heap.size()){
        int distance = heap.top().first; 
        int u = heap.top().second; 
        heap.pop();
        
//        cerr << "debug: " << u << " " << dist2[u] << " " << dist[u] << " " << f[c[u]] << "\n";
        
        ans = min(ans, dist2[u] + dist[u]);
        ans = min(ans, dist2[u] + f[c[u]]);
        
        if(!vis[c[u]]){
            vis[c[u]] = 1;
            for(auto v : h[c[u]]){
                if(dist2[v] != INF) continue;
                dist2[v] = dist2[u];
                heap.push({dist2[v], v});     
            }
        }
        
        for(auto v : g[u]){
            if(dist2[v] != INF) continue;
            dist2[v] = dist2[u] + 1;
            heap.push({dist2[v], v}); 
        }
    } 
    
    return ans;
} 

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>c[i];
        h[c[i]].push_back(i);
    }
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }
    while(m--){
        int s,t; cin>>s>>t;
        cout << calc(s, t) << "\n";
    }
}

signed main(){
    IOS;
    solve();
    return 0;
} 

/*
6 3
1 3 2 1 2 3
1 2
1 3
2 4
2 5
3 6
2 6
3 2
4 3

0
1
1
*/

/*
6 1
1 1 2 2 3 3
1 2
2 3
3 4
4 5
5 6
1 6

2
*/

