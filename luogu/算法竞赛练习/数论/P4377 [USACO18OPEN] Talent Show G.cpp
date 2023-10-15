#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const double eps = 1e-8;
int n,m;
int a[N],b[N]; // a 才艺 b 重量
long double dp[N]; // dp[j] 表示体积至少为j的最大价值 初始化 dp[0] = 0 else dp[j] = -inf   

bool check(double x){
    for(int i=1;i<=m;i++) dp[i] = -1e9;  //至少背包初始化 不合法状态
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            if(dp[j] > -1e9){
                int k = min(m,j+b[i]);
                dp[k] = max(dp[k],dp[j]+a[i]-x*b[i]);
            }
        }
    }
    return dp[m] >= 0;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>b[i]>>a[i];
    double l = 0 , r = 1000.0;
    while(r - l > eps){
        double mid = (l + r) / 2;
        //cout << l << " " << r << " " << mid << "\n";
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << (int)(r * 1000) << "\n"; // 1066
    //printf("%d\n",r*1000); //错误写法 可能会爆精度 输出错误数字 -1411500032
    return 0;
}
