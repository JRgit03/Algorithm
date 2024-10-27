#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){ return a > b ? a : b;}
int min(int a,int b){ return a < b ? a : b;}

const int N = 1e6 + 10;
int n;
int vis[N];
vector<int> g[N];

int mp[N], tot;
int sz[N];

void dfs(int u){
    for(auto &v : g[u]){
        if(vis[v]) continue;
        vis[v] = 1;
        mp[v] = tot;
        sz[tot] += 1;
        dfs(v);
    }
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) {
        int u = i, v; cin>>v;
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]) {
            vis[i] = 1;
            tot += 1;
            sz[tot] += 1;
            mp[i] = tot;
            dfs(i);
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans, sz[mp[i]]);
        if(i - 1 >= 1 && mp[i] != mp[i-1]) {
            ans = max(ans, sz[mp[i]] + sz[mp[i - 1]]);
        }
        if(i + 1 <= n && mp[i] != mp[i+1]) {
            ans = max(ans, sz[mp[i]] + sz[mp[i + 1]]);
        }
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
} 

/*
5
2 1 5 4 3

4
*/

/*
8
2 3 1 5 4 6 8 7

5
*/
