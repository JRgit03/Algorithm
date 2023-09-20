#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long 
using namespace std;
const int N = 1e5 + 10 , Mod = 1e9 + 7;
int n;
int a[N];
int dp[N]; // dp[i] 表示 以 a[i] 结尾 的所有连续子数组 的 权值和
int cnt[40][2]; // cnt[j][st] 表示 0 1 前缀和

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++){
        dp[i] = dp[i-1]; //不选
        for(int j=0;j<=30;j++){ // 选
            if((a[i] >> j) & 1){ 
                dp[i] = (dp[i] + 1LL * (1<<j) * cnt[j][0] % Mod) % Mod;
                cnt[j][1] = (cnt[j][1] + i) % Mod;   
            }else{
                dp[i] = (dp[i] + 1LL * (1<<j) * cnt[j][1] % Mod) % Mod;
                cnt[j][0] = (cnt[j][0] + i) % Mod; 
            }
        }
    }

    int ans = 0;
    for(int i=1;i<=n;i++) ans = (ans + dp[i]) % Mod;
    cout << ans << "\n";
}

signed main(){
    IOS; solve(); // 2^10 -> 1024 -> 2 ^ 30 
    return 0;
}
