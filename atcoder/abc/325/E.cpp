#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
typedef long long ll;
const int N = 1e3 + 10,INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int,int> PII;
int n,a,b,c;
int d[N][N];
int dist[N][2];
int st[N];

void dij(){
    for(int i=1;i<=n;i++) dist[i][0] = dist[i][1] = INF;
    memset(st,false,sizeof st);
    dist[1][0] = 0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1});
    while(heap.size()){
        auto [distance,u] = heap.top(); heap.pop();
        if(st[u]) continue;
        st[u] = true;
        for(int v=1;v<=n;v++){
            if(dist[v][0] > distance + d[u][v] * a){
                dist[v][0] = distance + d[u][v] * a;
                heap.push({dist[v][0],v});
            }
        }
    } 
    memset(st,false,sizeof st);    
    dist[n][1] = 0;
    heap.push({0,n});
    while(heap.size()){
        auto [distance,u] = heap.top(); heap.pop();
        if(st[u]) continue;
        st[u] = true;
        for(int v=1;v<=n;v++){
            if(dist[v][1] > distance + d[u][v] * b + c){
                dist[v][1] = distance + d[u][v] * b + c;
                heap.push({dist[v][1],v});
            }
        }
    } 
    int ans = INF;
    for(int i=1;i<=n;i++) ans = min(ans,dist[i][0] + dist[i][1]);
    cout << ans << "\n"; 
}

signed main(){
    IOS;
    cin>>n>>a>>b>>c;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>d[i][j];
    dij();
    return 0;
}
