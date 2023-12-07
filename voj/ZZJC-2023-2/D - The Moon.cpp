#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    for(int T=1;T<=t;T++){
        double p; cin>>p; p /= 100;
        vector<double> dp(1010,0); dp[1000] = 1.0 / p; // dp[i]表示q的概率为i时期望的游戏局数  
        for(int i=999;i>=0;i--){
            double q = i * 1.0 / 1000;
            dp[i] = p * q * 1 + (1-p) * (dp[min(1000,i+15)] + 1) + p * (1 - q) * (dp[min(1000,i+20)] + 1);
        }
        printf("Case %d: %.10lf\n",T,dp[20]);
    }
    return 0;
}
