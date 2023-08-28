#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> h[N];

void dfs(int u,int fa,int d,vector<int> &dist){
    dist[u] = d;
    for(auto v : h[u]){
        if(v==fa)continue;
        dfs(v,u,d+1,dist);
    }
}

void solve(){
    int n,m;cin>>n;m=n-1;
    for(int i=0;i<n;i++)h[i].clear();

    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;u--,v--;
        h[u].push_back(v);
        h[v].push_back(u);
    }
    vector<int> dist1(n),dist2(n);
    dfs(0,-1,0,dist1);
    int dl = max_element(dist1.begin(),dist1.end()) - dist1.begin();
    dfs(dl,-1,0,dist1);
    int dr = max_element(dist1.begin(),dist1.end()) - dist1.begin();
    dfs(dr,-1,0,dist2);
    
    //cout << dl << " " << dr << "\n";

    vector<int> ans(n+1); //ans[k] 长度<=k时的连通块数量  移除的点肯定孤立

    for(int i=0;i<n;i++)
        ans[max(dist1[i],dist2[i])+1]++;
    
    ans[0]++;
    ans[dist1[dr]+1]--;

    //for(int i=0;i<=n;i++) cout << "len " << i << " " << ans[i] << "\n";

    for(int i=1;i<=n;i++) {
        ans[i] += ans[i-1];
        cout << ans[i] << " \n"[i==n];
    }
}

int main(){
    int t=1;
    while(t--)solve();
    return 0;
}
