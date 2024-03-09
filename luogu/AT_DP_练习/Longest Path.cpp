#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int n,m;

int d[N];
int dp[N];
vector<int> g[N];

void solve(){
    cin>>n>>m;
    while(m--){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        d[v] += 1;
    }
    queue<int> q;
    for(int i=1;i<=n;i++) if(!d[i]) {
        q.push(i); dp[i] = 0;
    }
    while(q.size()){
        int x = q.front(); q.pop();
        for(auto y : g[x]){
            dp[y] = max(dp[y], dp[x] + 1);
            if(--d[y] == 0){
                q.push(y);
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) ans = max(ans, dp[i]);
    cout << ans << "\n";
}

signed main(){
    solve();
    return 0;
}
