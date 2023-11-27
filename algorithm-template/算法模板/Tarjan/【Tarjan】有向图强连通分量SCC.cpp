/**
 * https://www.luogu.com.cn/problem/P2863
 * output: 表示点数大于 1 的强连通分量个数。
 */

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int n,m;

vector<int> g[maxn];
// tot: 记录时间戳变量
// dfn[x]: 节点x第一次被访问的时间戳 
// low[x]: 从节点x出发,所能访问到的最早时间戳, [更新low值的目的：避免SCC节点提前出栈]
int dfn[maxn],low[maxn],tot; 
int stk[maxn],instk[maxn],top;
// cnt: 记录scc编号
// scc[x]: 节点x所属强连通分量的编号
// siz[x]: 编号为x的强连通分量的大小
int scc[maxn],siz[maxn],cnt; 

void tarjan(int x){
    // 入x时,记录首次访问的时间
    dfn[x] = low[x] = ++tot; 
    stk[++top] = x; instk[x] = 1;
    // 处理邻点
    for(int y : g[x]){
        if(!dfn[y]){
            tarjan(y);
            low[x] = min(low[x], low[y]); // 回x时,更新low[x] 即节点y可以访问到的时间戳 x一定可以访问到
        }else if(instk[y]){ //若y已经访问且在栈中, 即处理回退边 说明y是祖先节点或左子树节点 用dfn[y]更新low[x]
            low[x] = min(low[x], dfn[y]);
        } // 若y已经访问且不在栈中 说明y所在连通分量已被处理
    }
    // 离x时, 记录SCC
    if(dfn[x] == low[x]){ //若x是SCC的根  一个强连通分量的根 dfn = low
        int y; ++cnt;
        do{
            y = stk[top--]; instk[y] = 0;
            scc[y] = cnt; // scc编号
            ++siz[cnt];   // scc大小
        }while(y!=x);
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++)  // 图可能不连通
        if(!dfn[i])
            tarjan(i);
    // for(int i=1;i<=n;i++) cout << dfn[i] << " " << low[i] << "\n";
    int ans = 0;
    for(int i=1;i<=cnt;i++) ans += siz[i] > 1;
    cout << ans << "\n";
    return 0;
}
