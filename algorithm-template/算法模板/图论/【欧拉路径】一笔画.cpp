/**
 *  无向图的度数：每个点所连接的边数
 * 
 *  1.对于无向图，所有边均连通
 *   (1)存在欧拉路径的充分必要条件：度数为奇数的点只能有0或2个
 *   (2)存在欧拉回路的充分必要条件：度数为奇数的点只能有0个
 *  2.对于有向图，所有边都是连通
 *   (1)存在欧拉路径的充分必要条件：要么所有点出度等于入度
 *                               要么除了两个点外其余所有点的出度等于入度
 *                               剩余两个点：一个满足出度比入度多1（起点），另一个满足入度比出度多1(终点)
 *   (2)存在欧拉回路的充分必要条件：所有点的出度均等于入度
 */

/**
 *  有向图判断是否存在欧拉路径
 *  https://www.luogu.com.cn/problem/P7771
 */
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 1e5 + 10 , M = N << 1;
int n,m;
int del[N]; //删边数组
int din[N],dout[N]; // din入度 dout出度
vector<int> g[N]; //存图
int ans[M],cnt; //存欧拉路径 

void dfs(int u){
    for(int i=del[u];i<g[u].size();i=del[u]){
        del[u] = i+1;
        dfs(g[u][i]);
    }
    ans[++cnt] = u;
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        int u,v; cin>>u>>v;
        dout[u]++ , din[v]++;
        g[u].push_back(v); 
    }
    for(int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());
    int f = 1; //是否所有点的出度=入度
    int stCnt = 0 , edCnt = 0 , st; 
    for(int i=1;i<=n;i++){
        if(din[i] != dout[i]) {
            f = 0;
            if(dout[i] - din[i] == 1){
                stCnt++ , st = i;
            }else if(din[i] - dout[i] == 1 ){
                edCnt++;
            }else{
                cout << "No" << "\n"; 
                return;
            }
        }
    }
    // 欧拉回路 or 欧拉路径
    if(!f && !(stCnt == edCnt && stCnt == 1)) {
        cout << "No" << "\n";
        return;
    }
    if(f) st = 1; //注意 欧拉回路任意点都可以当起点
    dfs(st);
    for(int i=cnt;i>0;i--) cout << ans[i] << " ";
 }

int main(){
    IOS; solve();
    return 0;
}

/**
 * 对于欧拉路径，我们一般采用Hierholzer算法
   ----首先我们要确定出起点，然后从起点开始不走重复边的递归。
   ----对于每一个点,当访问完所有的边时，把这个点加入答案序列。
   ----最后，输出答案序列即为一条欧拉路径依次经过的点。
*/

/**
 * 相关例题
 * 
 * 骑马修栅栏
 * https://www.acwing.com/problem/content/1126/
 * 
 * 
 * 