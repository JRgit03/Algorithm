#include <bits/stdc++.h>
using namespace std;
const int N = 210 , INF = 0x3f3f3f3f;
int n,m,T;
int dist[N][N];
int way,mind=INF,xh;

void solve(){
    int k;cin>>k;
    vector<int> cnt(n+1);
    vector<int> path;path.push_back(0);
    for(int i=0;i<k;i++){
        int x;cin>>x;path.push_back(x);
        cnt[x]++;
    }
    path.push_back(0);
    for(int i=1;i<=n;i++)
        if(cnt[i]!=1)
            return;
    int d = 0;
    for(int i=1;i<=n+1;i++){
        int u = path[i-1] , v = path[i];
        // cout << u << " " << v << "\n";
        if(dist[u][v]==INF)return;
        d += dist[u][v];
    }
    //cout << T << " " << d << "\n";
    way++;
    if(d < mind){
        mind = d , xh = T;
    }
}

int main(){
    memset(dist,0x3f,sizeof dist);
    for(int i=1;i<=n;i++)dist[i][i]=0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        dist[u][v] = dist[v][u] = min(dist[u][v],w);
    }
    int q;cin>>q;
    for(T=1;T<=q;T++)solve();
    cout << way << "\n";
    cout << xh << " " << mind << "\n";
    return 0;
}
