#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e4 + 10;
int n,m;
int ans;
int st[N];
vector<int> g[N];

void dfs(int u,int k,int h){
    if(k == 4){
        ans += 1;
        return;
    }
    for(auto &v : g[u]){
        if(!st[v]){
            if(v == h){
                if(k == 3){
                    st[v] = 1;
                    dfs(v, k+1, h);
                    st[v] = 0;
                }
            }else{
                st[v] = 1;
                dfs(v, k+1, h);
                st[v] = 0;
            }
        }
    }
}

// dfs解法
void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }    
    
    for(int i=1;i<=n;i++) dfs(i,1,i);
    cout << ans << "\n";
}

// 固定中转边b->c  a->b->c->d 对于当前中转边为b->c来说 可行方式数有(d[b] - 1) * (d[c] - 1)
void solve2(){
    cin>>n>>m;
    vector<int> d(n+1);
    vector<pair<int,int>> edges;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        d[u] += 1, d[v] += 1;
        edges.push_back({u,v});
    }
    int ans = 0;
    for(int i=0;i<m;i++){
        auto [u,v] = edges[i];
        ans += (d[u] - 1) * (d[v] - 1) * 2;
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    // solve();
    solve2();
    return 0;
}
