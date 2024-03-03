#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e3 + 10;
int n,m;

struct Node{
    int x,y,w;
    
    bool operator < (const Node& o) const {
        return x != o.x ? x < o.x : y < o.y;
    }
};

Node segs[N];
vector<int> g[N];
int val[N];

int check(int i,int j){
    int f1 = (segs[i].x == segs[j].x || segs[i].y == segs[j].y || segs[i].y == segs[j].x);
    int f2 = (segs[j].x >= segs[i].x && segs[j].x <= segs[i].y && segs[j].y >= segs[i].y);
    return f1 || f2;
}

int vis[N];
int dp[N][2]; 

void dfs(int u,int f){
    dp[u][0] = -val[u], dp[u][1] = 0; // 1 保留 0 舍弃编号为u的线段
    for(auto &v : g[u]){
        if(v == f || vis[v]) continue;
        vis[v] = 1;
        dfs(v,u);
        dp[u][0] += dp[v][1];
        dp[u][1] += dp[v][0];
    }
}


signed main(){
    memset(dp,0x3f,sizeof dp);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y,w; cin>>x>>y>>w;
        segs[i] = {x,y,w};
    }
    sort(segs + 1, segs + 1 + m);
    // int sum = 0;
    for(int i=1;i<=m;i++) {
        // cout << "seg: " << segs[i].x << " " << segs[i].y << "\n";
        val[i] = segs[i].w; 
        // sum += val[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=i+1;j<=m;j++){
            if(check(i,j)){
                // cout << "edge: " << i << "->" << j << "\n"; 
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    int maxs = 0;
    for(int i=1;i<=m;i++)
        if(!vis[i]){
            vis[i] = 1;
            dfs(i,i);
            // cout << i << " " << max(dp[i][0], dp[i][1]) << "\n";
            maxs += max(dp[i][0], dp[i][1]);
        }
    cout <<  -maxs << "\n";
    return 0;
}
