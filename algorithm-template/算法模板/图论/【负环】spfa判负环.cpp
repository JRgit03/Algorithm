/**
 * https://www.luogu.com.cn/problem/P3385 
 */
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 2e3 + 10 , INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
int n,m;
int dist[N]; //dist[x]存储1号点到x点的最短距离
int cnt[N];  //cnt[x]存储1号点到x的最短路中经过的点数
int inq[N];   //存储每个点是否在队列

vector<PII> g[N];

// 存在负环 返回true
// 原理:  如果某个点的最短路上有n个点（除了本身）-> n+1 
//        由抽屉原理得出一定存在两个点相同
bool spfa(){
    dist[1] = 0 , inq[1] = 1;
    queue<int> q; q.push(1); //从1出发是否存在负环
    // for(int i=1;i<=n;i++) q.push(i) , inq[i] = true; // 整个图中是否存在负环 
    while(q.size()){
        int u = q.front(); q.pop();
        
        inq[u] = 0;

        for(auto [v,w] : g[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1;
                if(cnt[v] >= n) return true;
                if(!inq[v]){
                    q.push(v) , inq[v] = 1;
                }
            }
        } 
    }
    return false;
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) dist[i] = INF , cnt[i] = inq[i] = 0 , g[i].clear();
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
        if(w>=0) g[v].push_back({u,w});
    }
    cout << (spfa() ? "YES" : "NO") << "\n";
}

int main(){
    IOS;
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
