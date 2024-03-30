// 线性dp 种类数少
// https://www.acwing.com/problem/content/314/
#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[550],b[5];
int dp[44][44][44][44]; // dp[b1,b2,b3,b4] 表示第i种卡片用完bi张的最大分数

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<m;i++) {
        int x;cin>>x; 
        b[x] += 1;
    }
    dp[0][0][0][0] = a[1];
    for(int i=0;i<=b[1];i++){
        for(int j=0;j<=b[2];j++){
            for(int x=0;x<=b[3];x++){
                for(int y=0;y<=b[4];y++){
                    int t = i * 1 + j * 2 + x * 3 + y * 4;
                    int &v = dp[i][j][x][y];
                    if(i - 1 >= 0) v = max(v, dp[i-1][j][x][y] + a[t + 1]);
                    if(j - 1 >= 0) v = max(v, dp[i][j-1][x][y] + a[t + 1]);
                    if(x - 1 >= 0) v = max(v, dp[i][j][x-1][y] + a[t + 1]);
                    if(y - 1 >= 0) v = max(v, dp[i][j][x][y-1] + a[t + 1]);
                }
            }
        }
    }
    cout << dp[b[1]][b[2]][b[3]][b[4]] << "\n";
}

signed main(){
    solve();
    return 0;
}
