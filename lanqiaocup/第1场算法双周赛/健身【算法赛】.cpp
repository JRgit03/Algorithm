#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int n,m,q;
int bad[N];
int last[N]; // last[i] 表示第i天往前可以持续多少天（包括第i天）
int dp[N]; // dp[i] 表示前i天的可以获得的最大价值
int v[N],w[N]; // v体积 w价值

signed main(){
    IOS;
    cin>>n>>m>>q;
    for(int i=0;i<q;i++){
        int x; cin>>x;
        bad[x] = 1;
    }
    for(int i=1;i<=m;i++){
        cin>>v[i]>>w[i];  v[i] = 1LL << v[i];
    }
    int pre = 0;
    for(int i=1;i<=n;i++){
        if(!bad[i]) last[i] = i - pre;
        else pre = i;
    }
    //for(int i=1;i<=n;i++) cout << "last: " << i << " " << last[i] << "\n";
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        dp[i] = dp[i-1];
        if(bad[i]) continue;
        for(int j=1;j<=m;j++){
            if(last[i] >= v[j]) dp[i] = max(dp[i],dp[i-v[j]]+w[j]);
        }
        // cout << "dp[i]:" << i << " " << dp[i] << "\n";
    }
    cout << dp[n] << "\n";
    return 0;
}
