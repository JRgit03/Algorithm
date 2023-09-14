#include <bits/stdc++.h>
using namespace std;
const int N = 55 , M = 1e3 + 10 , INF = 1e6;
int n,m;
int dist[N][N][M];
double d[N][N];

void solve(){
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        if(dist[u][v][1] == 0) dist[u][v][1] = w;
        else dist[u][v][1] = min(dist[u][v][1], w);
    }
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)  
            for(int m1=1;m1<=m;m1++)
                if(dist[i][j][m1] == 0)
                    dist[i][j][m1] = INF;
    /**
     * 动态规划的核心思想是将原问题划分为若干个子问题，
     * 并利用子问题的解来逐步求解原问题的解。
     * 子问题之间有时存在依赖关系，即某个子问题的解依赖于其他子问题的解。
     * 这就要求我们按照一定的顺序解决子问题，以保证每个子问题的依赖关系能够得到满足
     */
	for(int m1=2;m1<=m;m1++) //m1 从小 到 大
	    for(int i=1;i<=n;i++)
	        for(int j=1;j<=n;j++)
	            for(int k=1;k<=n;k++)
                    dist[i][j][m1] = min(dist[i][j][m1], dist[i][k][m1-1] + dist[k][j][1]);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            d[i][j] = INF;
            for(int m1=1;m1<=m;m1++)
                if(dist[i][j][m1] != INF) 
                    d[i][j] = min(d[i][j],dist[i][j][m1]*1.0/m1);
        }
        
     
    
    int q; cin>>q;
    for(int i=0;i<q;i++){
        int u,v; cin>>u>>v;
        if(d[u][v] < 100000.0 && u != v) printf("%.3lf\n",d[u][v]);
        else printf("OMG!\n");
    }
}

signed main(){
    solve(); return 0;
}
