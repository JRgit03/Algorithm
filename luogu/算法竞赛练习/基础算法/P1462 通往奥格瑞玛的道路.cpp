#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N = 1e4 + 10 , INF = 0x3f3f3f3f;
int n,m,b;
bool st[N];
int cost[N];

int dist[N];
vector<PII> g[N];

bool check(int cmax){
    memset(dist,0x3f,sizeof dist);
    memset(st,false,sizeof st);
    dist[1] = 0; if(cost[1] > cmax) return false;
    priority_queue<PII,vector<PII>,greater<PII> > heap;
    heap.push({0,1});
    
    while(heap.size()){
        auto [distance,u] = heap.top(); heap.pop();

        if(st[u]) continue;
        st[u] = true;

        for(auto &[v,w] : g[u]){
            if(cost[v] <= cmax && dist[v] > distance + w){
                dist[v] = distance + w;
                heap.push({dist[v],v});
            }
        }
    }

    return dist[n] <= b;
}

void solve(){
    cin>>n>>m>>b;
    for(int i=1;i<=n;i++) cin>>cost[i];
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    int l = 0 , r = *max_element(cost+1,cost+1+n);
    while(l<r){ //二分最大的一次缴费
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    if(check(r)) cout << r << "\n";
    else cout << "AFK" << "\n";
}

int main(){
    IOS; solve();
    return 0;
}
