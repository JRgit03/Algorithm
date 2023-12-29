// https://www.luogu.com.cn/problem/P8436
// 双连通仅针对无向图！
// 边双连通图：一个没有桥的连通图。
// 边双连通分量：极大的边双连通子图
// e-DCC就是边连通分量，原图中一个极大的连通子图（子图没有桥）
// e-DCC缩点 将同一个边连通分量内的点看作一个点，将桥当作边连通分量之间的边

// 练习https://codeforces.com/contest/178/problem/B1
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 4e6 + 10;
int n,m;
// h[i] 存储第i个结点的头结点的下标
// e[i] 存储结点i的值
// ne[i] 存储结点i的下一个结点的下标
// idx 存储当前可用的结点的下标
int h[N], e[M], ne[M], idx;

// 有向边 a -> b
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int bridge[M];
int dfn[N],low[N],tot;
int e_dcc[N]; // e_dcc[x] = y 表示 点x属于编号为y的边双连通分量

void tarjan(int x,int in_edge){
    dfn[x] = low[x] = ++tot;
    for(int i=h[x];~i;i=ne[i]){
        int y = e[i];
        if(!dfn[y]){
            tarjan(y,i);
            if(dfn[x] < low[y]) bridge[i] = bridge[i^1] = 1;
            low[x] = min(low[x], low[y]);
        }else if(i != (in_edge ^ 1)) { // 返祖边
            low[x] = min(low[x], dfn[y]);
        }
    }
}

// 求边双连通分量
// 方法：对原图求连通块，遇到割边continue
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
// 缩点建立新图：将每一个边双连通分量看作一个点
// 将割边看作双连通分量之间的边即可
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

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) h[i] = h2[i] = -1; 
    idx = 2; // idx初始化为2 e[i] 与 e[i^1] 成对处理有向
    while(m--){
        int u,v; scanf("%d%d",&u,&v);
        if(u == v) continue; //自环
        add(u,v); add(v,u);
    }
    for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,0);
    for(int i=1;i<=n;i++) if(!e_dcc[i]){
        ++edcc_cnt; dfs(i);
    }
    // debug e-dcc缩点后的边双连通分量个数 每个边双连通块内成员
    printf("%d\n",edcc_cnt); 
    map<int,vector<int>> mp;
    for(int i=1;i<=n;i++) mp[e_dcc[i]].push_back(i);
    for(auto [p,vec] : mp) {
        printf("%d ",vec.size());
        for(int i=0;i<vec.size();i++) printf("%d ",vec[i]); printf("\n");
    }
    // build();
    return 0;
}
