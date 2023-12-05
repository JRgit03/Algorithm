#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 10;
int n;
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

int din[maxn],dout[maxn];
vector<int> e[maxn];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int to; while(cin>>to){
            if(!to) break;
            g[i].push_back(to);
        }
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
    for(int x=1;x<=n;x++){
        for(int y : g[x]){
            if(scc[x] != scc[y]){
                dout[scc[x]] += 1; din[scc[y]] += 1;
                e[scc[x]].push_back(scc[y]);
            }
        }
    }
    // cout << cnt << "\n";
    // for(int i=1;i<=n;i++) cout << scc[i] << " "; cout << "\n";
    int ans1 = 0, a = 0, b = 0;
    for(int i=1;i<=cnt;i++) {
        if(!din[i]) ans1 += 1, a += 1;
        if(!dout[i]) b += 1;
    }
    cout << ans1 << "\n";
    cout << max(a,b) << "\n";
    return 0;
}
