#include <bits/stdc++.h>
using namespace std;
int a,b,c;
double dp[20][20][20][20];

void solve(){
    double a,b,c; cin>>a>>b>>c;
    memset(dp,0,sizeof dp);
    dp[0][0][0][0] = 1.0;
    for(int i=1;i<=16;i++){
        for(int x=0;x<=16;x++)
            for(int y=0;y<=16;y++)
                for(int z=0;z<=16;z++){
                    dp[i][x][y][z] = dp[i-1][x][y][z];
                    if(x-1>=0) dp[i][x][y][z] += dp[i-1][x-1][y][z] * (a / 16);
                    if(y-1>=0) dp[i][x][y][z] += dp[i-1][x][y-1][z] * (b / 16);
                    if(z-1>=0) dp[i][x][y][z] += dp[i-1][x][y][z-1] * (c / 16);
                }
    }
    printf("%.10lf\n",dp[16][16][0][0] + dp[16][12][4][0] + dp[16][12][0][4]);
}

int main(){
    int t; cin>>t;
    while(t--) 
        solve();
    return 0;
}
