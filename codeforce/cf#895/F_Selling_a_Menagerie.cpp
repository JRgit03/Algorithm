#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> d(n+1),vis(n+1),c(n+1);
    vector<int> g[n+1];
    for(int u=1;u<=n;u++){
        int v; cin>>v;
        g[u].push_back(v); d[v]++;
    }
    for(int i=1;i<=n;i++) cin>>c[i];

    vector<int> ans;
    queue<int> q;

    for(int i=1;i<=n;i++)
        if(!d[i]){
            q.push(i); 
            vis[i] = 1;
        }
    
    while(q.size()){
        int u = q.front(); q.pop(); ans.push_back(u);
        
        for(auto v : g[u]){
            if(--d[v] == 0){
                q.push(v);
                vis[v] = 1;
            }
        }
    }

    vector<int> vec; map<int,int> dest;
    function<void(int)> dfs = [&](int u) -> void {
        for(auto v : g[u])
            if(!vis[v]){
                dest[u] = v;
                vec.push_back(v); 
                vis[v] = 1;
                dfs(v);
            }
    };

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            sort(vec.begin(),vec.end(),[&](const int i,const int j){
                return c[i] < c[j];
            });
            int p = vec[0];
            for(int i=0;i<vec.size();i++) ans.push_back(dest[p]) , p = dest[p]; 
            vec.clear(); dest.clear();
        }
    }

    for(int i=0;i<n;i++) cout << ans[i] << " \n"[i == n-1];

}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
