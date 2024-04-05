#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b) {return (a > b ? a : b);}
int min(int a,int b) {return (b > a ? a : b);}

const int N = 2e3 + 10, mod = 998244353;
int n;
int c[N];
int dp[N][N];
int f[N][N];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i];   
    dp[0][0] = f[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j] = dp[i-1][j];
            f[i][j] |= f[i-1][j];
            if(c[i] == 0 || c[i] > n) continue;
            if(j - c[i] >= 0) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-c[i]]) % mod;
                f[i][j] |= f[i-1][j-c[i]];
            }
        }
    }
    for(int j=n;j>=0;j--)
        if(f[n][j]){
            cout << j << " " << dp[n][j] << "\n";
            return;
        }
}

signed main(){
    IOS; solve();
    return 0;
}
