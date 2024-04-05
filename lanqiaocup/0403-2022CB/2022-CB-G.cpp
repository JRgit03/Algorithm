#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;
const int N = 1e7 + 10, mod = 1e9 + 7;
int max(int a,int b){ return (a > b ? a : b);}
int min(int a,int b){ return (a < b ? a : b);}
int dp[4];
void solve(){
 	int n; cin>>n; 
 	dp[1] = 1, dp[2] = 2, dp[3] = 5;
 	if(n <= 3) {
 		cout << dp[n] << "\n";
 		return;
	}
	for(int i=4;i<=n;i++){
	    dp[4] = (2 * dp[3] + dp[1]) % mod;
 		dp[1] = dp[2], dp[2] = dp[3], dp[3] = dp[4];
	} 
	cout << (dp[4] % mod + mod) % mod << "\n";
	return;
}

signed main(){
	IOS;
	solve();
	return 0;
} 
	
/*
n	ans
1	1
2	2
3	5
4   11
5   dp[i] = 2 * dp[i - 1] + dp[i - 3] ²ÂÏë 
*/
