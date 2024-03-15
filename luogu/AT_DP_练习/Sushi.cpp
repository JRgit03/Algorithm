#include <bits/stdc++.h>
using namespace std;
const int N = 3e2 + 10;
int n, a[N], cnt[4]; 
double dp[N][N][N];

// 期望值 = 概率 * 贡献积的总和
// 有n个盘子，每个盘子有ai个寿司每次等概率选择一个盘子吃掉其中一个寿司，
// 选到空盘子不变化，求吃完所有寿司的期望步数。
// n <= 300 ai <= 3

// 考虑到 ai <= 3 显然 只需要关心每个盘子中剩余的寿司数量
// dp[i,j,k] 表示 当前 剩余1/2/3个寿司的盘子数分别为i/j/k,吃完全部的期望次数

// dp[i,j,k] = 1 + 2 + 3 + 4 
// 1.当前选到空盘子             (n - i - j - k) * (dp[i,j,k] + 1) / n 
// 2.当前选到剩余1个寿司的盘子   i * (dp[i-1,j,k] + 1) / n
// 3.当前选到剩余2个寿司的盘子   j * (dp[i+1,j-1,k] + 1) / n
// 4.当前选到剩余3个寿司的盘子   k * (dp[i,j+1,k-1] + 1) / n
// Q: 为什么都要加一? A: 代表状态转移的操作步数代价为1
// 整理得 dp[i,j,k] = (i * dp[i-1,j,k] + j * dp[i+1,j-1,k] + k * dp[i,j+1,k-1] + n) / (i + j + k) 

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]; 
        cnt[a[i]] += 1;
    }
    function<double(int,int,int)> dfs = [&](int i,int j,int k) -> double {
        if(i == 0 && j == 0 && k == 0) return 0.0; //递归边界
        if(dp[i][j][k] != 0.0) return dp[i][j][k];
        double &res = dp[i][j][k];
        res = 1.0 * n / (i + j + k);
        if(i) res += 1.0 * i * dfs(i-1,j,k) / (i + j + k);
        if(j) res += 1.0 * j * dfs(i+1,j-1,k) / (i + j + k);
        if(k) res += 1.0 * k * dfs(i,j+1,k-1) / (i + j + k);
        return res;
    }; 
    printf("%.10lf\n", dfs(cnt[1], cnt[2], cnt[3]));
}

signed main(){
    solve();
    return 0;
}
