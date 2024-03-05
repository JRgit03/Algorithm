/**
 * https://www.luogu.com.cn/problem/P3379
 */

/**
 * 注意depth为深度数组 即权值为1的特殊情况
 * 区分dist 和 depth的区别 ！！！
 */
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 5e5 + 10 , INF = 0x3f3f3f3f;
int n,q,root;
int depth[N];
int fa[N][20]; // f[i,j] 表示从点i 开始往上走 2^j 步 所能走到的 0<=j<=log2(N)

vector<int> g[N];

void bfs(int root){
    memset(depth,0x3f,sizeof depth);
    depth[0] = 0; 
    depth[root] = 1;
    
    queue<int> q; q.push(root);

    while(q.size()){
        int u = q.front(); q.pop();
        for(auto &v : g[u])
            if(depth[v] > depth[u] + 1){
                depth[v] = depth[u] + 1;
                q.push(v);
                fa[v][0] = u;
                for(int k=1;k<=19;k++) //预处理 fa 数组
                    fa[v][k] = fa[fa[v][k-1]][k-1];
            }
    }    
}

int lca(int a,int b){
    // 方便处理 统一深的为a
    if(depth[a] < depth[b]) swap(a,b);
    // 使 a b 跳到同一高度 操作a
    for(int k=19;k>=0;k--)
        if(depth[fa[a][k]] >= depth[b])
            a = fa[a][k];
    if(a == b) return  a;
    // a b 同层但出于不同节点
    for(int k=19;k>=0;k--)
        if(fa[a][k] != fa[b][k]){
            a = fa[a][k];
            b = fa[b][k];
        }
    // 循环结束 到达lca下一层
    return fa[a][0];
}

int main(){
    IOS;
    cin>>n>>q>>root;
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v) , g[v].push_back(u);
    }
    bfs(root);
    for(int i=0;i<q;i++){
        int u,v;cin>>u>>v;
        cout << lca(u,v) << "\n";
    }
    return 0;
}
