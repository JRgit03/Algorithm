#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 11 + 10;
int n,m;
int vis[N];
vector<int> path;
void dfs(int i){
    if(i == m + 1){
        debug(path);
        return;
    }
    for(int j=1;j<=n;j++){
        if(!vis[j]){
            vis[j] = 1, path.push_back(j);
            dfs(i + 1);
            vis[j] = 0, path.pop_back();
        }
    }
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) {
        m = i;
        dfs(1);
    }    
}

signed main(){
    IOS;
    solve();
    return 0;
}
