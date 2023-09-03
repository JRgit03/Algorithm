#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 5e2 + 10;
int n,m,u,v,st;
int del[N];
int g[N][N]; //邻接表存图 利于删除无向边
int d[N];
int ans[N<<2],cnt;

// 时间复杂度 O(n^2)
void dfs(int u){
    for(int i=1;i<=n;i++){ //倒叙输出欧拉回路 要求从小到大遍历
        if(g[u][i]){
            g[u][i]-- , g[i][u]--;
            dfs(i);
        }
    }
    ans[++cnt] = u;
}

void solve(){
    n = 500; cin>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        g[u][v]++ , g[v][u]++;
        d[u]++ , d[v]++;
    }
    st = 1;
    while(!d[st]) st++; //找到第一个度数不为0的点

    for(int i=1;i<=500;i++){ //可能是欧拉路径 or 欧拉回路
        if(d[i]&1){
            st = i;
            break;
        }
    }
    dfs(st);
    for(int i=cnt;i;i--) cout << ans[i] << "\n";
}

int main(){
    IOS; solve();
    return 0;
}
