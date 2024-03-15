// 区间dp 石子合并 《算法竞赛》P352
// 小区间 => 大区间
// 题意: n个数, 第i个数值为ai, 每次操作的代价为合并的两个数之和,求n-1次合并后的最小代价
// n <= 400, ai <= 1e9
const int N = 4e2 + 10;
int n,a[N],s[N];
int dp[N][N];

// dp[i,j] 表示 合并区间i,j的最小代价
// dp[i,j] = min{dp[i,k] + dp[k+1,j] + s[i,j]} (i <= k < j) s为区间和
void solve(){
    // O(n ^ 3)
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) {
        dp[i][i] = 0; s[i] += s[i-1] + a[i];
    }
    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=n;l++){
            int r = l + len - 1;
            dp[l][r] = 1e18;
            for(int k=l;k<r;k++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r] + s[r] - s[l-1]);
            }
        }
    }
    cout << dp[1][n] << "\n";
}