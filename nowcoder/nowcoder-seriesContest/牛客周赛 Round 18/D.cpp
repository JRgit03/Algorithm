#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e3 + 10;
int n,m;
int ans;
int a[maxn],b[maxn];
// dp[i,j,k] 前i件物品体积不超过j且状态为k的最大价值
int dp[maxn][maxn][3]; // 0 半价 1 原价 2不买
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
    memset(dp,-0x3f,sizeof dp);
	dp[0][0][2] = 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(j-a[i]/2>=0) dp[i][j][0] = dp[i-1][j-a[i]/2][1] + b[i];
			if(j-a[i]>=0) dp[i][j][1] = max({dp[i-1][j-a[i]][1],dp[i-1][j-a[i]][0],dp[i-1][j-a[i]][2]}) + b[i];
            dp[i][j][2] = max({dp[i-1][j][0],dp[i-1][j][1],dp[i-1][j][2]});
			ans = max({ans,dp[i][j][0],dp[i][j][1],dp[i][j][2]});
		}
	}
	cout<< ans << "\n";
	return 0;
}