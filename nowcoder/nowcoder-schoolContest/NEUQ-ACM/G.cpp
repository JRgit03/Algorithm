#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e2 + 10, M = 2e5 + 10;
int n,m;
int a[N];
bitset<M> dp[N]; // dp[i,j] 表示前i个物品体积恰好为j的方案是否存在

void solve(){
    cin>>n;
    int sum = 0;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        sum += a[i];
    }
    m = sum / 2;
    dp[0].set(0,1);
    for(int i=1;i<=n;i++){
        dp[i] |= dp[i-1];
        dp[i] |= dp[i-1] << a[i];
    }
    int maxx = 0;
    for(int j=0;j<=m;j++)
        if(dp[n][j]) 
            maxx = j;   
    cout << abs(sum - maxx - maxx) << "\n";
}

signed main(){
    solve();
    return 0;
}
