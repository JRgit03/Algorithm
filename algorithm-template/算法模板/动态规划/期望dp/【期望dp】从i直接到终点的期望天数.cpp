/**
 * 题意：当前在第0关，要到第n关。每天可以选择：
 *  1.到第i+1关 
 *  2.以概率q[i]挑战，成功了直接到第n关，失败了回到第a[i](0<=a[i]<=i)关。
 *  问最优策略下，用尽可能少的天数到第n关的期望天数。
 * 
 *  题解：最优策略下 只会在一个点挑战 枚举每个点作为挑战点 取最小值
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n;
int a[N],q[N]; 
double dp[N]; // dp[i] 表示从第i天直接到终点第n天的期望天数

// dp[i] = p * 1 + (1 - p) * (i - a[i] + 1 + dp[i])
// => dp[i] = (p + (1 - p) * (i - a[i] + 1)) / p

void solve(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>q[i];
    double ans = n;
    for(int i=0;i<n;i++) {
        if(q[i] == 0) continue;
        double p = q[i] * 1.0 / 100000;
        dp[i] = (p + (1 - p) * (i - a[i] + 1)) / p;
        ans = min(ans, i + dp[i]);
    }
    printf("%.12lf\n", ans);
}

signed main(){
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

// E[x]=∑(X∗P),X是当前的结果,P是当前结果的概率
// 换句话说，期望等于每个数出现的概率乘以每个数的值
// 期望具有线性关系:E(ax1+bx2+...)=aE(x1)+bE(x2)+...+1
