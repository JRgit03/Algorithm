// dfs染色
// https://www.cnblogs.com/fightfordream/p/6519248.html 题解
// https://codeforces.com/gym/100502/ 源地址
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n,m;
int cnt1,cnt2;
int ans;
int suc = 1;
int vis[N];
int col[N]; // 1 染黑色 -1染白色 0未确定
vector<int> g[N];

// 当前遍历到u,点u的颜色为c,图的类型为kind
int dfs(int u,int c,int kind){
    if(!kind){
        if(col[u] == 1) ans += 1;
    }else{
        if(col[u] == 1) cnt1 += 1;
        else cnt2 += 1;
    }
    for(auto &v : g[u]){
        if(col[v] == c) return 0;
        if(vis[v]) continue;
        vis[v] = 1;
        if(col[v] == 0) col[v] = -c;
        if(!dfs(v,col[v],kind)) return 0;
    }
    return 1;
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c;
        if(c == 0){ // 两白
            if(col[a] == 1 || col[b] == 1) suc = 0;
            col[a] = col[b] = -1;
        }else if(c == 2){ // 两黑
            if(col[a] == -1 || col[b] == -1) suc = 0;
            col[a] = col[b] = 1;
        }else { // 一白一黑
            g[a].push_back(b); g[b].push_back(a);
        }
    }
    // col[i] = -1 or 1 点i颜色已经确定 则相邻的颜色选择也唯一
    for(int i=1;i<=n;i++) if(col[i] != 0 && !vis[i]) {
        vis[i] = 1;
        if(!dfs(i,col[i],0)) suc = 0;
    }
    // 剩余图中尚未染色的点 可以任意染色 
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        cnt1 = cnt2 = 0; col[i] = vis[i] = 1;
        if(!dfs(i,col[i],1)) suc = 0;
        ans += min(cnt1, cnt2);
    }
    if(suc == 0) cout << "impossible" << "\n";
    else cout << ans << "\n";
}

signed main(){
    solve();
    return 0;
}
