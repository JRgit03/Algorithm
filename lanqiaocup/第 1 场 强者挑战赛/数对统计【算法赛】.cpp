#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 10, mx = 1 << 20;
int n;
int a[maxn];
// 0010 -> 0/1 0/1 0 0/1 -> 1101 此处的1可以为0/1
// 1101 = 1101 + 0101 + 1001 + 0001 + 1100 + 0100 + 1000 + 0000
int dp[(1<<20)-1]; // dp[i] 用一个集合描述所有的合法状态结合

signed main(){
    cin>>n; 
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) dp[a[i]] += 1;
    for(int j=0;j<20;j++){ //从低位到高位考虑
        for(int i=0;i<mx;i++){
            if((i >> j) & 1){
                dp[i] += dp[i ^ (1 << j)];
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) ans += dp[a[i] ^ (mx - 1)];
    cout << ans << "\n";
    return 0;
}
