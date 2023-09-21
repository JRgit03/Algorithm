#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 330;
int n,m;
int w[N];
int notroot[N];
int f[N][N]; // f[i,j] 以i为根选j个物品的最大价值(包含i) 分组背包
vector<int> g[N];

void dfs(int u){
    for(auto v : g[u]){
        dfs(v);
        for(int i=m;i>=0;i--){ // i 要 从 大 到 小 更新 eg f[u][i] 要用到 f[u][i-j] 不能用本层的结果 要用上一层的结果
            for(int j=0;j<i;j++){ // 而 j f[v][...] 已经 更新完毕 遍历顺序没要求 
                f[u][i] = max(f[u][i],f[v][j]+f[u][i-j]);
            }
        }
    }
}

int main(){
    IOS;
    cin>>n>>m; m++;
    for(int i=1;i<=n;i++){
        int fa; cin>>fa>>f[i][1];
        g[fa].push_back(i); notroot[i] = 1;
    }
    for(int i=1;i<=n;i++)
        if(!notroot[i])
            g[0].push_back(i);
    dfs(0);
    cout << f[0][m] << "\n";
    return 0;
}
