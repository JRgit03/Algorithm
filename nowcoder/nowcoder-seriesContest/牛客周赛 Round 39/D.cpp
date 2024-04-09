#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e3 + 10;
int n,m;
int a[N];
int dp[N];

void solve(){
    cin>>n>>m; 
    queue<int> q;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        a[i] %= m;
        if(dp[a[i]] == 0) q.push(a[i]);
        dp[a[i]] = 1;
    }
    while(q.size()){
        int u = q.front(); q.pop();
        for(int i=1;i<=n;i++){
            int v = (a[i] + u) % m;
            if(dp[v] != 0) continue;
            dp[v] = dp[u] + 1;
            q.push(v);
        }
    }
    cout << dp[0] << "\n";
}

signed main(){
    solve();
    return 0;
}
