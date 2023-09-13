/**
 *  https://www.luogu.com.cn/problem/B3611
 *  连通性 关系的传递
 *  在图论中，传递闭包可以用来确定从一个节点到另一个节点是否存在路径
 *  在关系理论中，传递闭包用于确定两个元素之间是否存在某种关系的传递性
 */
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 1e2 + 10;
int n;

int d[N][N];
// floyd
void solve1(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>d[i][j];
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                d[i][j] |= (d[i][k] & d[k][j]); //判断连通性即可
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cout << d[i][j] << " \n"[j==n];
}

bitset<N> g[N]; 
// bitset优化 二进制数组
void solve2(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            int x; cin>>x; g[i][j] = x; //不能直接cin bitset数组
        }
    for(int i=1;i<=n;i++) // g[i]先不变
        for(int j=1;j<=n;j++)  
            if(g[j][i]) // j 与 i 连通 则 j 可以到达 i 可以到达 的 所有地方
                g[j] |= g[i];            
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cout << g[i][j] << " \n"[j==n];
}

int main(){
    IOS; solve2();
    return 0;
}
