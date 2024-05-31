#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e3 + 10, INF = 0x3f3f3f3f3f3f3f3f;
int n,m;
string s,t;
int dp[N][N]; // dp[i,j] 表示 s字符串的前i个字符的子序列包含t的前j个字符的最少修改次数

void solve(){
    cin>>s>>t;
    n = s.length(), m = t.length();
    s = "?" + s, t = "$" + t;
    memset(dp, 0x3f, sizeof dp);
    for(int i=0;i<=n;i++) dp[i][0] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = dp[i-1][j];
            if(s[i] == t[j]) dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            else dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
        }
    }    
    cout << dp[n][m] << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
