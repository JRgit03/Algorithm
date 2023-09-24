#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n,m;
int ans[N];
int vis[N];
vector<int> g[N];
vector<int> h[N];

void dfs(int u,int flag,int fa){
    if(ans[u] != -1) return;
    ans[u] = flag;

    for(auto v : g[u]){
        if(v == fa) continue;
        dfs(v,flag,u);
    }

    for(auto v : h[u])
        dfs(v,flag+1,-1);
}

int main(){
    memset(ans,-1,sizeof ans);
    scanf("%d %d",&n,&m);
    for(int i=2;i<=n;i++){
        int u; cin>>u;
        g[i].push_back(u);
        g[u].push_back(i);
    }
    vector<int> vec;
    for(int i=1;i<=m;i++){
        int a,b; cin>>a>>b;
        if(a == 1 || b == 1){
            if(a == 1){
                vec.push_back(b);
            }else{
                vec.push_back(a);
            }
        }
        h[a].push_back(b);
        h[b].push_back(a);
    }

    for(auto st : vec){
        // cout << "st: " <<  st << " " << flag << "\n";
        dfs(st,1,1);
    }

    for(int i=2;i<=n;i++) cout << ans[i] << " ";

    return 0;
}