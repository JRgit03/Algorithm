#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 55;
int n = 50;
int g[N][N];
int d[N];
vector<pair<int,int>> path;

// 欧拉路/回路 需要删边处理 走过的边不能重复走
void euler(int u){
    for(int v=1;v<=n;v++)
        if(g[u][v]){
            g[u][v]-- , g[v][u]--;
            euler(v); 
            path.push_back({v,u}); //欧拉回路要逆序输出
        }
}

int main(){
    int T; scanf("%d",&T);
    for(int t=1;t<=T;t++){
        if(t>1) printf("\n");
        path.clear();
        printf("Case #%d\n",t);
        memset(g,0,sizeof g);
        memset(d,0,sizeof d);
        int m; cin>>m;
        int st;
        for(int i=0;i<m;i++){
            int u,v; scanf("%d %d",&u,&v); st = u;
            d[u]++ , d[v]++;
            g[u][v]++ , g[v][u]++;
        }
        int ok = 1;
        for(int i=1;i<=n;i++)
            if(d[i] & 1){
                printf("some beads may be lost\n");
                ok = 0;
                break;
            }
        if(ok) {
            euler(st);
            if(path.size() != m || path.front().first != path.back().second) printf("some beads may be lost\n");
            else {
                for(auto &[u,v] : path) cout << u << " " << v << "\n";
            }
        }
    }
    return 0;
}