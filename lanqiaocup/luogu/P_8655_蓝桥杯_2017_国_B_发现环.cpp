#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e5 + 10;
int n;
int d[N];
vector<int> g[N];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int u,v; cin>>u>>v;
        d[u] += 1; d[v] += 1;
        g[u].push_back(v); g[v].push_back(u);
    }    
    queue<int> q;
    for(int i=1;i<=n;i++) if(d[i] == 1) {
        q.push(i);
    }
    while(q.size()){
        auto u = q.front(); q.pop();
        
        for(auto &v : g[u])
            if(--d[v] == 1)
                q.push(v);
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
