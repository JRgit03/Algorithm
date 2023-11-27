#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define dbug(x) cout << #x << '=' << x << endl
#define int long long
#define x first
#define y second
using namespace std;
const int N = 2e5 + 10, Mod = 1e9 + 7, INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
typedef pair<int,int> PII;
typedef long long ll;

int n,m;
vector<int> g[N];

int dfn[N],low[N],tot;
int stk[N],instk[N],top;
int scc[N],siz[N],cnt;

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

int din[N];
int w[N],nw[N];

void solve(){
    cin>>n>>m;
    tot = 0; top = 0; cnt = 0;
    for(int i=1;i<=n;i++) {
        g[i].clear(); dfn[i] = low[i] = 0; 
    }
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
    vector<int> e[cnt+1];
    for(int x=1;x<=n;x++){
        nw[scc[x]] += w[x];
        for(int y : g[x])
            if(scc[x] != scc[y]){
                din[scc[y]] += 1;
                e[scc[x]].push_back(scc[y]);
            }
    }
    // cout << cnt << "\n"; for(int i=1;i<=n;i++) cout << i << " " << scc[i] << "\n"; cout << "\n";
    // for(int x=1;x<=cnt;x++) for(int y : e[x]) cout << x << " " << y << "\n"; 
    [&](){
        vector<int> dist(cnt+1,-1),val(cnt+1,INF);
        queue<int> q;
        for(int i=1;i<=cnt;i++) if(!din[i]) {
            q.push(i); 
            dist[i] = siz[i]; val[i] = nw[i];
        }
        while(q.size()){
            auto u = q.front(); q.pop();
            for(int v : e[u]){
                if(dist[v] < dist[u] + siz[v]){
                    dist[v] = dist[u] + siz[v];
                    val[v] = val[u] + nw[v];
                }else if(dist[v] == dist[u] + siz[v]){
                    val[v] = min(val[v], val[u] + nw[v]);
                }
                if(--din[v] == 0){
                    q.push(v);
                }
            }
        }
        int maxdist = -1, minval = INF;
        for(int i=1;i<=cnt;i++){
            if(dist[i] > maxdist){
                maxdist = dist[i];
                minval = val[i];
            }else if(dist[i] == maxdist){
                minval = min(minval, val[i]);
            }
        }
        cout << maxdist << " " << minval << "\n";
    }();
    for(int i=1;i<=cnt;i++) nw[i] = din[i] = siz[i] = 0;
}

signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
