#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 4e6 + 10;
int n,m;

int h[N], e[M], ne[M], idx;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int bridge[M];
int dfn[N],low[N],tot;
int e_dcc[N]; 

void tarjan(int x,int in_edge){
    dfn[x] = low[x] = ++tot;
    for(int i=h[x];~i;i=ne[i]){
        int y = e[i];
        if(!dfn[y]){
            tarjan(y,i);
            if(dfn[x] < low[y]) bridge[i] = bridge[i^1] = 1;
            low[x] = min(low[x], low[y]);
        }else if(i != (in_edge ^ 1)) {
            low[x] = min(low[x], dfn[y]);
        }
    }
}

int edcc_cnt;
void dfs(int x){
	e_dcc[x] = edcc_cnt;
    //cout << "debug: " << x << " " << e_dcc[x] << "\n";
	for (int i = h[x]; ~i; i = ne[i]){
		int y = e[i];
		if (e_dcc[y] || bridge[i])continue;
		dfs(y);
	}
}

int h2[N], e2[M], ne2[M], idx2;
void add2(int a, int b){
    e2[idx2] = b, ne2[idx2] = h2[a], h2[a] = idx2 ++ ;
}

void build(){
    for(int i=2;i<idx;i++){
        int x = e[i];
        int y = e[i^1];
        if(e_dcc[x] == e_dcc[y]) continue;
        add2(e_dcc[x],e_dcc[y]);
    }
    // printf("show new graph\n");
    // for(int x=1;x<=edcc_cnt;x++)
    //     for(int i=h2[x];~i;i=ne2[i])
    //         printf("%d->%d\n",x,e2[i]);
}

int depth[N];
int fa[N][20];

void bfs(int root){
    memset(depth,0x3f,sizeof depth);
    depth[0] = 0; 
    depth[root] = 1;
    
    queue<int> q; q.push(root);

    while(q.size()){
        int u = q.front(); q.pop();
        for(int i=h2[u];~i;i=ne2[i]){
            int v = e2[i];
            if(depth[v] > depth[u] + 1){
                depth[v] = depth[u] + 1;
                q.push(v);
                fa[v][0] = u;
                for(int k=1;k<=19;k++) 
                    fa[v][k] = fa[fa[v][k-1]][k-1];
            }
        }    
    }    
}

int lca(int a,int b){
    if(depth[a] < depth[b]) swap(a,b);
    for(int k=19;k>=0;k--)
        if(depth[fa[a][k]] >= depth[b])
            a = fa[a][k];
    if(a == b) return  a;
    for(int k=19;k>=0;k--)
        if(fa[a][k] != fa[b][k]){
            a = fa[a][k];
            b = fa[b][k];
        }
    return fa[a][0];
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) h[i] = h2[i] = -1; 
    idx = 2;
    while(m--){
        int u,v; scanf("%d%d",&u,&v);
        if(u == v) continue; 
        add(u,v); add(v,u);
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,0);
    for(int i=1;i<=n;i++) if(!e_dcc[i]){
        ++edcc_cnt; dfs(i);
    }
    // printf("%d\n",edcc_cnt); 
    // map<int,vector<int>> mp;
    // for(int i=1;i<=n;i++) mp[e_dcc[i]].push_back(i);
    // for(auto [p,vec] : mp) {
    //     printf("%d ",vec.size());
    //     for(int i=0;i<vec.size();i++) printf("%d ",vec[i]); printf("\n");
    // }
    build();
    bfs(1);
    int m; scanf("%d", &m);
    while(m--){
        int a,b; scanf("%d%d",&a,&b);
        a = e_dcc[a], b = e_dcc[b];
        printf("%d\n", depth[a] + depth[b] - 2 * depth[lca(a,b)]);
    }
    return 0;
}
