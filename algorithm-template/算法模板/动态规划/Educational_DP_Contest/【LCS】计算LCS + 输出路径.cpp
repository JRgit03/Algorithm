// 最长公共子序列 + 输出路径
void solve(){
    cin>>a>>b;
    n = a.length(); m = b.length();
    a = "?" + a; b = "$" + b;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(a[i] == b[j]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        } 
    }
    vector<char> path;
    while(dp[n][m]){
        if(a[n] == b[m]){
            path.push_back(a[n]);
            n -= 1; m -= 1;
        }else{
            if(dp[n][m] == dp[n-1][m]) n -= 1;
            else m -= 1;
        }
    }
    reverse(path.begin(), path.end());
    for(auto c : path) cout << c;
}