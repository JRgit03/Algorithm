// https://leetcode.cn/problems/selling-pieces-of-wood/description/?envType=daily-question&envId=2024-03-15
// 线性dp 切木块
/*
题意：
    给定一块 n * m 的 木块 以及 
    prices[i] = [hi, wi, pricei] 表示你可以 priceI 元的价格卖一块高为 hi 宽为 wi 的矩形木块。
    每一次操作中，你必须按下述方式之一执行切割操作，以得到两块更小的矩形木块：
    1.沿垂直方向按高度 完全 切割木块
    2.沿水平方向按宽度 完全 切割木块 
    (注意是完全切割,一次切割操作会变成两块木块)
    每个primes[i]可以任意次，求请你返回切割一块大小为 n x m 的木块后，能得到的 最大价值
*/

class Solution {
public:
    long long sellingWood(int n, int m, vector<vector<int>>& prices) {
        // pr[i,j] 表示切割一块高i宽j的木块的最大价值
        int pr[n+1][m+1];  memset(pr, 0, sizeof pr);
        for(auto &p : prices) pr[p[0]][p[1]] = max(pr[p[0]][p[1]], p[2]);
        long long dp[n+1][m+1]; memset(dp, 0, sizeof dp);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                // 1.直接买
                dp[i][j] = pr[i][j]; 
                // 2.枚举水平切割点 宽度不变
                for(int k=1;k<i;k++) dp[i][j] = max(dp[i][j], dp[k][j] + dp[i-k][j]);
                // 3.枚举垂直切割点 高度不变
                for(int k=1;k<j;k++) dp[i][j] = max(dp[i][j], dp[i][k] + dp[i][j-k]);
            }
        }
        return dp[n][m];
    }
};


// eg
// in:  m = 3, n = 5, prices = [[1,4,2],[2,2,7],[2,1,3]]
// out: maxV = 19

