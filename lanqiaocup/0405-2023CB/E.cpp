#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define int long long
using namespace std;

int max(int a,int b){return (a > b ? a : b); }
int min(int a,int b){return (a < b ? a : b); }

const int N = 1e6 + 10;
int n;
string a[N];
int dp[N][11]; // 前i个数且以j结尾的最小代价 

void solve(){
    memset(dp, 0x3f, sizeof dp);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int j=0;j<10;j++) dp[0][j] = 0;
    for(int i=1;i<=n;i++){
        int pre = a[i][0] - '0', suf = a[i].back() - '0';
        dp[i][suf] = dp[i - 1][pre];
        for(int j=0;j<10;j++) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
        
    }
    int ans = n;
    for(int j=0;j<10;j++) ans = min(ans, dp[n][j]);
    cout << ans << "\n";
}

signed main(){
    IOS; solve();
    return 0;
} 

/*
5
11 121 22 12 2023
*/
