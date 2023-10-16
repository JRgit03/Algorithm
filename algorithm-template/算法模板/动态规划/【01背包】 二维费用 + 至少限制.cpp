/**
 * 01背包 二维费用至少 最小代价问题
 * https://www.acwing.com/problem/content/1022/
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n,v1,v2;
int a[N],b[N],c[N];
// int dp[N][30][80]; //dp[i,j,k] 前i件物品 氧量至少为j 氮量至少为k 的 最小代价
// int main(){
//     cin>>v1>>v2>>n;
//     for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
//     memset(dp,0x3f,sizeof dp); dp[0][0][0] = 0; // dp[][j][k] 将所有j<0 && k<0的状态压缩在 dp[][0][0]
//     for(int i=1;i<=n;i++){
//         for(int j=0;j<=v1;j++){
//             for(int k=0;k<=v2;k++){
//                 dp[i][j][k] = dp[i-1][j][k];
//                 int x = max(0,j-a[i]) , y = max(0,k-b[i]);
//                 dp[i][j][k] = min(dp[i][j][k],dp[i-1][x][y]+c[i]);
//             }
//         }
//     }
//     cout << dp[n][v1][v2] << "\n";
//     return 0;
// }

int dp[30][80]; //dp[i,j,k] 前i件物品 氧量至少为j 氮量至少为k 的 最小代价
int main(){
    cin>>v1>>v2>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
    memset(dp,0x3f,sizeof dp); dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=v1;j>=0;j--){
            for(int k=v2;k>=0;k--){
                int x = max(0,j-a[i]) , y = max(0,k-b[i]);
                dp[j][k] = min(dp[j][k],dp[x][y]+c[i]);
            }
        }
    }
    cout << dp[v1][v2] << "\n";
    return 0;
}