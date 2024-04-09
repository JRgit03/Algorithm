/**
 * 题意：给定n个数字按钮,每个数字按钮可以选择1~m的数字,要求任意相邻的按钮之差的绝对值>=k
 *       n <= 1000, m <= 5000,  0 <= k <= m - 1;
 * 思路：定义dp状态 dp[i,j]前i个数且第i个数且j的合法方案数, ans = sum(dp[n][j]) 1<=j<=m
 *      dp[i,j] = dp[i-1][1 ~ j-k] + dp[i-1][j+k ~ m] 注意需要特判两部分贡献可能有交集
 */
const int mod = 998244353;
int n,m,k;
int s[5050];
int dp[1010][5010]; 

int sum(int l,int r){
    if(l > r) return 0;
    return ((s[r] - s[l-1]) % mod + mod) % mod;
}

void solve(){
    cin>>n>>m>>k;
    for(int j=1;j<=m;j++) dp[1][j] = 1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++) s[j] = (s[j - 1] % mod + dp[i - 1][j] % mod) % mod; 
        for(int j=1;j<=m;j++) {
            if(j - k != j + k) dp[i][j] = (sum(1, j - k) % mod + sum(j + k, m) % mod) % mod;
            else dp[i][j] = (sum(1, j - k - 1) % mod + sum(j + k, m) % mod) % mod;
        }
    }
    int ans = 0;
    for(int j=1;j<=m;j++) ans = (ans + dp[n][j]) % mod;
    cout << (ans % mod + mod) % mod  << "\n";
}