#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
int n,m;
int dp[N][N];
string a,b;

int main(){
    cin>>a>>b; n = a.length(); m = b.length(); a = "?" + a , b = "$" + b;
    for(int i=1;i<=n;i++) dp[i][0] = i;
    for(int i=1;i<=m;i++) dp[0][i] = i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = min(dp[i-1][j]+1,dp[i][j-1]+1);
            dp[i][j] = min(dp[i][j] , dp[i-1][j-1] + (a[i] != b[j]));
        }
    }
    cout << dp[n][m] << "\n";
    return 0;
}