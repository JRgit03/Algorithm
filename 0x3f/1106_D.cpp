#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n,m;
bool vis[maxn];
vector<int> g[maxn];
vector<int> ans;

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }
    priority_queue<int,vector<int>,greater<int> > heap;
    heap.push(1);
    while(heap.size()){
        int u = heap.top(); heap.pop();
        if(vis[u]) continue;
        vis[u] = true;
        ans.push_back(u);
        for(auto v : g[u])
            heap.push(v);   
    }
    for(auto x : ans) cout << x << " ";
    return 0;
}

// 最小堆 模拟 最小堆存放的是当前可到达的点 因为不限制次数可以多次折返！
