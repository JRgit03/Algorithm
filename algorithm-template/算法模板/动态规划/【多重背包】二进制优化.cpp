/**
 * 模板题
 * 多重背包(有限个物品)二进制优化 -> 01背包
 * https://www.luogu.com.cn/problem/P1776
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10, M = 4e4 + 10;
int n,m;
int v[N],w[N],cnt; // v体积 w价值
int dp[M]; // dp[i,j] 前i个物品且体积不超过j的最大价值
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a,b,s; cin>>a>>b>>s; //a价值 b体积 s个数
        int k=1; while(s >= k || s){
            cnt++;
            if(s >= k){
                v[cnt] = b * k;
                w[cnt] = a * k;
                s -= k; k <<= 1;
            }else{
                v[cnt] = b * s;
                w[cnt] = a * s;
                s = 0;
            }
        }
    }
    n = cnt;
    for(int i=1;i<=n;i++)
        for(int j=m;j>=v[i];j--)
            dp[j] = max(dp[j],dp[j-v[i]]+w[i]);
    cout << dp[m] << "\n";
    return 0;
}
