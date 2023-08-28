    // 约瑟夫环问题 从后往前推
    int lastRemaining(int n, int m) {
        int dp[n+1]; dp[1] = 0; // dp[i]表示 0~i-1循环删除第m个数 最后剩下的数为 dp[i]
        for(int i=2;i<=n;i++){
            dp[i] = (dp[i-1] + m) % i;
        }
        return dp[n];
    }