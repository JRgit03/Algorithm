#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 1e2 + 10;
int n,m;
int a[N][N];
int dp[N][N];

// O(sqrt(1e6) * n * m) = 1e8
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++) 
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    auto check = [&](int k){ //可达性分析
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 && j == 0) {
                    dp[0][0] = 1;
                    continue;
                }
                dp[i][j] = 0;
                if(a[i][j] % k == 0){
                    if(i - 1 >= 0) dp[i][j] |= dp[i-1][j];
                    if(j - 1 >= 0) dp[i][j] |= dp[i][j-1];
                }
            }
        }
        return dp[n-1][m-1];
    };
    int x = __gcd(a[0][0], a[n-1][m-1]); 
    int ans = 0;
    for(int i=1;i<=x/i;i++){ // 枚举a[0][0]与a[n-1][m-1]的最大公约数的因子 
        if(x % i == 0){
            if(check(i)) ans = max(ans, i);
            if(check(x/i)) ans = max(ans, x/i);
        }
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    int t; cin>>t;
    while(t--) solve();
    return 0;
}


/*
10000
20 1
720720
720720
720720
720720
720720
720720
720720
720720
720720
720720
720720
720720
720720
720720
720720
720720
720720
720720

10000 / 20 * 240 * 20 * 1 = 2e7 
*/