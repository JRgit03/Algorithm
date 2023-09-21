#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 2e3 + 10;
int n;
int f[N][2]; // f[i,j] 表示 以 i 为 根节点 j为状态的 最少放置士兵数目 j = 0 不放置 j = 1 放置
vector<int> g[N];

void dfs(int u,int fa){
    f[u][1] = 1;
    f[u][0] = 0;
    
    for(auto v : g[u]){
        if(v == fa) continue;
        dfs(v,u);
        f[u][0] += f[v][1];
        f[u][1] += min(f[v][0],f[v][1]);    
    }
}

int main(){
    IOS;
    cin>>n;
    for(int i=0;i<n;i++){
        int u,k,v; cin>>u>>k;
        while(k--){
            cin>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    dfs(1,-1);
    cout << min(f[1][0],f[1][1]) << "\n";
    return 0;
}
