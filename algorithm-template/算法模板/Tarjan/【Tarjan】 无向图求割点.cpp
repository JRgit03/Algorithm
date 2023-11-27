/**
 * https://www.luogu.com.cn/problem/P3388
 * 割点： 对于一个无向图,如果删除点x,连通块个数增加,则称x为割点
 * 割点的判定： low[y] >= dfn[x]
 *             非根节点需要找到一颗子树,根节点需要找到两颗子树
 */
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n,m;

vector<int> g[maxn];
int dfn[maxn],low[maxn],tot;
int cut[maxn],root;

void tarjan(int x){
    // 入x时 盖戳
    dfn[x] = low[x] = ++tot;
    int child = 0; // 子树个数
    for(int y : g[x]){
        if(!dfn[y]){ // 邻点y未访问
            tarjan(y);
            low[x] = min(low[x],low[y]);
            if(low[y] >= dfn[x]){
                child++;
                if(x!=root || child > 1){
                    cut[x] = true;
                }
            }
        }else{
            low[x] = min(low[x],dfn[y]);
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }    
    for(int i=1;i<=n;i++) if(!dfn[i]) {
        root = i; tarjan(i);
    }
    vector<int> ans;
    for(int i=1;i<=n;i++) if(cut[i]) ans.push_back(i);
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x << " "; 
    return 0;
}