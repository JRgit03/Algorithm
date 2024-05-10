// https://www.lanqiao.cn/problems/108/learning/?page=1&first_category_id=1&second_category_id=3&tags=%E5%9B%BD%E8%B5%9B
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e6 + 10;
int n; 
int d[N];
vector<int> g[N];

// 无向图找环 n点n边
// 拓扑排序后度数为2的点即为环上点
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
        d[v] += 1, d[u] += 1;
    }
    queue<int> q;
    for(int i=1;i<=n;i++) if(d[i] == 1) {
        q.push(i);
    }
    while(q.size()){
        int u = q.front(); q.pop();
        for(auto &v : g[u]){
            if(--d[v] == 1){
                q.push(v);
            }
        }
    }
    for(int i=1;i<=n;i++) if(d[i] == 2) {
        cout << i << " ";
    }
}

signed main(){
    IOS;
    solve();
    return 0;
}
