#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n,m;
int a[N],b[N];
int vis[N]; // 2 未访问 0 白色 1 黑色
set<int> g[N];

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) vis[i] = 2;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    int f = 0;
    for(int i=1;i<=m;i++){
        int u = a[i], v = b[i];
        g[u].insert(v), g[v].insert(u);
    }
    auto bfs = [&](int u){
        queue<pair<int,int>> q; q.push({u,1}); vis[u] = 1;
        while(q.size()){
            auto [u,color] = q.front(); q.pop();
            for(auto v : g[u]){
                if(vis[v] == 2){
                    vis[v] = !color;
                    q.push({v,!color});
                }else if(vis[v] == vis[u]){
                    f = 1;
                }
            }
        }
    };
    for(int i=1;i<=n;i++){
        if(vis[i] == 2){
            bfs(i);
        }
    }
    cout << (f ? "No" : "Yes") << "\n";
    return 0;
}
