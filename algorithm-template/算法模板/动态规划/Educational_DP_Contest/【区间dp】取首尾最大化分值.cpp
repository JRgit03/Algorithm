const int N = 3e3 + 10;
int n,a[N];
// 题意: 一组数字每次取首或者尾,求先手后手的最大分差 => 先手取得的最大值 - 后手取得的值

//方案1
// dp[i,j] 从区间[i,j]先手可以取得的最大值
int dp[N][N];
void solve(){
    cin>>n;
    int sum = 0;
    for(int i=1;i<=n;i++) {
        cin>>a[i]; sum += a[i];
    }
    function<int(int,int)> dfs = [&](int i,int j) -> int {
        if(i == j) return dp[i][j] = a[i];
        if(i + 1 == j) return dp[i][j] = max(a[i], a[j]);
        if(dp[i][j]) return dp[i][j];
        int &res = dp[i][j];
        res = max(a[i] + min(dfs(i+2,j), dfs(i+1,j-1)), a[j] + min(dfs(i+1,j-1), dfs(i,j-2)));
        return res;
    }; dfs(1,n);
    int ans = dp[1][n] - (sum - dp[1][n]);
    cout << ans << "\n";
}

//方案2
// f[i,j] 区间[i,j]最大化分差 (对于先手值越大分差越大, 对于后手值越小分差越大)
// 先手取 f[i,j] = max(f[i+1,j] + a[i], f[i,j-1] + a[j]) 
// 后手取 f[i,j] = min(f[i+1,j] - a[i], f[i,j-1] - a[j]);
int f[N][N];
void solve2(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int len=1;len<=n;len++){ // 枚举区间长度
        for(int l=1;l+len-1<=n;l++){ // 枚举左端点
            int r = l + len - 1; // n - len 已取数量 
            if((n - len) & 1) f[l][r] = min(f[l+1][r] - a[l], f[l][r-1] - a[r]);
            else f[l][r] = max(f[l+1][r] + a[l], f[l][r-1] + a[r]); 
        }
    }
    cout << f[1][n] << "\n";
}