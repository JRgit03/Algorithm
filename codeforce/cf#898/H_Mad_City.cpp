#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;
const int N = 2e5 + 10 , INF = 0x3f3f3f3f;
int n,a,b; // a 抓 b 跑
int dist[N];

void solve(){
    cin>>n>>a>>b; a--; b--;
    vector<int> d(n);
    vector<int> g[n];
    for(int i=0;i<n;i++){
        int u,v; cin>>u>>v; u--; v--;
        g[u].push_back(v); g[v].push_back(u);
        d[u]++; d[v]++;
    }    

    if(a == b) {
        cout << "NO" << "\n";
        return;
    }
    
    queue<int> q;
    for(int i=0;i<n;i++)
        if(d[i] == 1)
            q.push(i);

    while(q.size()){
        auto u = q.front(); q.pop();
        
        for(auto v : g[u])
            if(--d[v] == 1)
                q.push(v);
    }       

    if(d[b] > 1){ // b 在环上
        cout << "YES" << "\n";
        return;
    }

    typedef pair<int,int> PII;
    function<PII(int)> getpoint = [&](int u) -> PII {
        int distance,point;
        for(int i=0;i<n;i++) dist[i] = INF; dist[u] = 0;
        queue<int> q; q.push(u);

        while(q.size()){
            int u = q.front(); q.pop();

            for(auto v : g[u]){
                if(dist[v] == INF){
                    dist[v] = dist[u] + 1;
                    if(d[v] > 1) return {dist[v],v};
                    q.push(v);
                }
            }
        }

        return {-1,-1};
    };

    auto [distb,point] = getpoint(b);
    // a 到 b->环口的距离
    for(int i=0;i<n;i++) dist[i] = INF; dist[a] = 0;
    q.push(a);

    while(q.size()){
        int u = q.front(); q.pop();

        for(auto v : g[u]){
            if(dist[v] == INF){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    int dista = dist[point];

    cout << (distb < dista ? "YES" : "NO") << "\n";
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
