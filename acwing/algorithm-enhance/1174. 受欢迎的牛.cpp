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
            low[x] = min(low[x],low[y]);
        }else if(instk[y]){
            low[x] = min(low[x],dfn[y]);
        }
    }
    if(dfn[x] == low[x]){
        int y; ++cnt;
        do{
            y = stk[top--]; instk[y] = 0;
            scc[y] = cnt;
            ++siz[cnt];
        }while(x != y);
    }
}

int din[maxn],dout[maxn];
vector<int> e[maxn];

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
    for(int x=1;x<=n;x++){
        for(int y : g[x]){
            if(scc[x] != scc[y]){
                din[scc[y]] += 1; dout[scc[x]] += 1;
                e[scc[x]].push_back(scc[y]);
            }
        }
    }
    int ans = 0, outSize = 0;
    for(int i=1;i<=cnt;i++){
        if(!dout[i]){
            outSize += 1;
            ans = siz[i];
        }
    }
    cout << (outSize > 1 ? 0 : ans) << "\n";
    return 0;
}
