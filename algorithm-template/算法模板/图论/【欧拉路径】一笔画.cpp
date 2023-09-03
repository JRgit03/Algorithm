/**
 *  无向图的度数：每个点所连接的边数
 * 
 *  1.对于无向图，所有边均连通
 *   (1)存在欧拉路径的充分必要条件：度数为奇数的点只能有0或2个
 *   (2)存在欧拉回路的充分必要条件：度数为奇数的点只能有0个
 *  2.对于有向图，所有边都是连通
 *   (1)存在欧拉路径的充分必要条件：要么所有点的初读均等于入度，
 *                               要么除了两个点外其余所有点的出度等于入度
 *                               剩余两个点：一个满足出度比入度多1（起点），另一个满足入度比出度多1(终点)
 *   (2)存在欧拉回路的充分必要条件：所有点的出度均等于入度
 */
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve(){
    
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
