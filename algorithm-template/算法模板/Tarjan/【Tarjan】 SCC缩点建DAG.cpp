/**
 * 有向图有环图 ==Tarjan缩点==> 有向无环图(拓扑图)
 * 缩点后 观察新图中点的出入度情况 构造答案
 * 所点后 重建拓扑图 利用拓扑图递推 找出答案
 * https://www.luogu.com.cn/problem/P3387
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int n,m;

vector<int> g[maxn];
int dfn[maxn],low[maxn],tot;
int stk[maxn],instk[maxn],top;
int scc[maxn],siz[maxn],cnt;

void tarjan(int x){
    dfn[x] = low[x] = ++tot;
    stk[++top] = x; instk[x] = 1;
    for(int y : g[x]){
        if(!dfn[y]){
            tarjan(y);
            low[x] = min(low[x], low[y]);
        }else if(instk[y]){
            low[x] = min(low[x], dfn[y]);
        }
    }
    if(dfn[x] == low[x]){
        int y; ++cnt;
        do{
            y = stk[top--]; instk[y] = 0;
            scc[y] = cnt;
            ++siz[cnt];
        }while(y != x);
    }
}

// nw: 建DAG后每个强连通分量的点权
vector<int> e[maxn];
int w[maxn],nw[maxn]; 


int dp[maxn];
void solve_dp(){
    // 逆序遍历scc 由于tarjan遍历的顺序 先dfs到的点scc编号大 即 大 -> 小
    for(int x=cnt;x;x--){
        if(dp[x] == 0) dp[x] = nw[x];
        for(int y : e[x])
            dp[y] = max(dp[y], dp[x] + nw[y]);
    }
    int ans = 0;
    for(int i=1;i<=cnt;i++) ans = max(ans, dp[i]);
    cout << ans << "\n";
}


// 拓扑排序解决dp无后效性 以正确的顺序访问
int din[maxn],dist[maxn];
void solve_topsort(){
    queue<int> q;
    for(int i=1;i<=cnt;i++) if(!din[i]) {
        q.push(i);
        dist[i] = nw[i];
    }
    while(q.size()){
        int u = q.front(); q.pop();
        for(int v : e[u]){
            dist[v] = max(dist[v], dist[u] + nw[v]);
            if(--din[v] == 0){
                q.push(v);
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=cnt;i++) ans = max(ans, dist[i]);
    cout << ans << "\n";
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
    // 缩点后建拓扑图 
    for(int x=1;x<=n;x++){
        nw[scc[x]] += w[x];
        for(int y : g[x])
            if(scc[x] != scc[y]){
                din[scc[y]] += 1;
                e[scc[x]].push_back(scc[y]);
            }
    }
    srand((int)time(0));
    int res = rand() % 2;
    if(res) solve_dp();
    else solve_topsort();
    return 0;
}
