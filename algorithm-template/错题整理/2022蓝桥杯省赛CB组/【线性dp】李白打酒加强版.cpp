/*  
    题意：初始有两斗酒,求经过n个店m朵花后的剩余酒斗数为0的方案数,已知最后一次访问的是花
          经过店当前酒*2, 经过花当前酒数-1,       n,m <= 200,
    思路：线性dp 定义dp[i,j,k] 走了前i个位置 遇到j个花 还剩k斗酒的方案数, 初始化dp[0][0][2] = 1
          ans = dp[n + m - 1][m - 1][1] 经过n+m-1位置,遇到第m-1个花,剩余一斗酒的方案数
*/
int n,m;
int dp[N][N][N];
void solve(){
    cin>>n>>m;
    dp[0][0][2] = 1;
    for(int i=1;i<=n+m;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=200;k++){
                if((k + 1) & 1) dp[i][j][k] += dp[i-1][j][k / 2];
                if(j-1 >= 0) dp[i][j][k] += dp[i-1][j-1][k+1];
                dp[i][j][k] %= mod;
            }
        }
    }   
    cout << dp[n+m-1][m-1][1] << "\n";
}