#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
int r,c;

int dx[] = {-1,-1,-1,0,1,1,1,0};
int dy[] = {-1,0,1,1,1,0,-1,-1};

void solve(int r,int c){
    vector<string> g(r+1);
    for(int i=1;i<=r;i++) cin>>g[i], g[i] = "?" + g[i];
    int dist[r+2][c+2]; memset(dist,0x3f,sizeof dist);
    deque<PII> deq;
    for(int i=0;i<=c+1;i++) dist[0][i] = 0, deq.push_back({0,i});
    for(int i=0;i<=r+1;i++) dist[i][c+1] = 0, deq.push_back({i,c+1});
    while(deq.size()){
        auto [x,y] = deq.front(); deq.pop_front();  
        for(int i=0;i<8;i++){
            int u = x + dx[i], v = y + dy[i];
            if(u < 1 || u > r || v < 1 || v > c) continue;
            if(g[u][v] == '@') continue;
            if(dist[u][v] != INF) continue; 
            int w = (g[u][v] == '#' ? 0 : 1);
            if(dist[u][v] > dist[x][y] + w){
                dist[u][v] = dist[x][y] + w;
                if(w == 0) deq.push_front({u,v});
                else deq.push_back({u,v});
            }
        }
    }
    int ans = INF;
    for(int i=1;i<=r;i++) ans = min(ans,dist[i][1]);
    for(int i=1;i<=c;i++) ans = min(ans,dist[r][i]);
    if(ans == INF) ans = -1;
    cout << ans << "\n";
}

int main(){
    while(cin>>r>>c){
        if(!r && !c) break;
        solve(r,c);
    }
    return 0;
}
