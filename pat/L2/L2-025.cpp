#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n,m;
vector<int> h[N];

bool att[N] , vis[N];

void dfs(int u,bool &f){
    vis[u] = true;
    if(!f)return;
    int cnt = 0;
    for(auto v : h[u])
        if(!att[v] && !vis[v]){
            cnt++;
            //cout << u << " " << v << "\n";
            dfs(v,f);
        }
            
    if(cnt) f = false;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        h[u].push_back(v);
        h[v].push_back(u);
    }
    int q;cin>>q;
    while(q--){
        memset(att,false,sizeof att);
        memset(vis,false,sizeof vis);
        int k;cin>>k;
        for(int i=0;i<k;i++){
            int x;cin>>x;att[x]=true;
        }
        bool f = true;
        for(int i=1;i<=n;i++)
            if(!att[i] && !vis[i])
                dfs(i,f);
        cout << (f ? "YES" : "NO") << "\n";
    }
    return 0;
}
