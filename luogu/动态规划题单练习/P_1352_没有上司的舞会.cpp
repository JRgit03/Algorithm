#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;
const int N = 6e3 + 10 , INF = 0x3f3f3f3f;
int n;
int val[N],d[N];
vector<int> g[N];
int f[N][2];

void dfs(int u){
    f[u][0] = 0 , f[u][1] = val[u];
    for(auto v : g[u]){
        dfs(v);
        f[u][1] += f[v][0];
        f[u][0] += max(f[v][0],f[v][1]);
    }
    //cout << u << " " << f[u][0] << " " << f[u][1] << "\n";
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=0;i<n-1;i++){
        int v,u; cin>>v>>u;
        g[u].push_back(v); d[v]++;
    }
    int root = 1;
    while(d[root]) root++;
    dfs(root);
    cout << max(f[root][0],f[root][1]) << "\n";
}

int main(){
    IOS; solve();
    return 0;
}
