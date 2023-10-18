/**
 * P3388 【模板】割点（割顶）
 * https://www.luogu.com.cn/problem/P3388
 * 割点/边：割去该点连通分量增多
 */

// tarjin图不一定连通的情况
#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10;
int n,m;
int timestamp;
int vis[N];
int dfn[N]; //图的dfn序 dfs遍历的顺序编号
int low[N]; //low[u]表示 u节点及其子树经过1条返祖边可以访问的最小编号
int ans; //割点数量
bool isCut[N]; 
vector<int> g[N];

void dfs(int u,int fa){
    dfn[u] = low[u] = ++timestamp; 
    int child = 0;
    for(auto v : g[u]){
        if(!dfn[v]){ //v点未被访问
            child++;
            dfs(v,u);
            low[u] = min(low[u],low[v]); // low[v] 更新 low[u]
            //判断非根节点是否是割点
            if(u != fa && low[v] >= dfn[u] && !isCut[u]) { //在v的支路上不存在返祖边回退到u的祖先
                isCut[u] = true; //标记割点
                ans++;
            } 
        }else if(v != fa && dfn[v] < dfn[u]){ // v的dfn序比u小 且u-v连通且v!=fa => 回退边
            low[u] = min(low[u],dfn[v]);
        }
    } 
    //判断根节点是否是割点
    if(u == fa && child >= 2 && !isCut[u]) { 
        isCut[fa] = true;//标记割点
        ans++;
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            dfs(i,i);
    cout << ans << "\n";
    for(int i=1;i<=n;i++) if(isCut[i]) cout << i << " ";
    return 0;
}
