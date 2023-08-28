#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10 , INF = 0x3f3f3f3f;
int n;
int v[N];
// f[i,j,k] 表示 前i天第i天的状态为k且至多完成了j笔交易 k=0不持股k=1持股 
int f[N][3][2];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>v[i];
    memset(f,-0x3f,sizeof f);
    f[0][0][0] = 0 , f[0][0][1] = -INF;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=2;j++){
            f[i][j][0] = f[i-1][j][0];
            if(j) f[i][j][0] = max(f[i][j][0],f[i-1][j-1][1]+v[i]);
            f[i][j][1] = max(f[i-1][j][1],f[i-1][j][0]-v[i]);
        }
    int ans = 0;
    for(int j=0;j<=2;j++) ans = max(ans,f[n][j][0]);
    cout << ans << "\n";
    return 0;
}
