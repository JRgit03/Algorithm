#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){ return (a > b ? a : b);}
int min(int a,int b){ return (a < b ? a : b);}
const int N = 200 + 10, mod = 1e9 + 7;
int n,m;
// dp[i,j,k] 走了前i个位置 遇到j个花 还剩k斗酒的方案数 
// ans = dp[n + m - 1][m - 1][1] 
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

signed main(){
	IOS;
	solve();
	return 0;
} 
