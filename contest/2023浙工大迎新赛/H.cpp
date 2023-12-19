#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int a[400][400];
map<long long,long long> dp[400][400]; // dp[i,j,k] 到达点i,j值为k的方案数。 将>=k的都压缩在dp[i,j,k]

int main(){
    int n,m,k; scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    dp[1][1][min(k,a[1][1])] = 1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(i-1>=1) for(auto &item : dp[i-1][j]) {
                int val = item.first, sz = item.second;
                dp[i][j][min(1LL*k,1LL*val*a[i][j])] += sz;
                dp[i][j][min(1LL*k,1LL*val*a[i][j])] %= mod;
            }
            if(j-1>=1) for(auto &item : dp[i][j-1]) {
                int val = item.first, sz = item.second;
                dp[i][j][min(1LL*k,1LL*val*a[i][j])] += sz;
                dp[i][j][min(1LL*k,1LL*val*a[i][j])] %= mod;
            }
        }
    printf("%lld\n",dp[n][m][k]);
    return 0;
}
