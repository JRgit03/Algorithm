#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e2 + 10, M = 1e3 + 10;
int n,m;
int a[N],b[N],c[N];
int dp[N][M]; 

// dp[i,j] 前i个鱼塘第j分钟的最大钓鱼数
// O(n*T*T)
void solve(){
    memset(dp, -0x3f, sizeof dp);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n-1;i++) cin>>c[i];
    cin>>m;
    int ans = 0;
    for(int i=0;i<=m;i++) dp[0][i]=0;
    dp[1][0]=0; //注意此处初始化i>1是dp[i][0]不一定合法,因为i~i+1需要c[i]的时间!
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x = j - c[i-1];
            if(x < 0) continue;
            dp[i][j] = dp[i-1][x]; 
            int aval = a[i], sum = a[i];
            while(aval > 0 && x > 0){
                x -= 1;
                dp[i][j] = max(dp[i][j], dp[i-1][x] + sum);
                aval -= b[i];
                sum += aval;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
}

signed main(){
    solve();
    return 0;
}
