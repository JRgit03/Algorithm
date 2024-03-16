#include <bits/stdc++.h>
#define int long long
using namespace std;
// 状态dp 二分图完全匹配的合法方案数
//题目:n男n女,已知每对男女之间是否可以配对，要求配成n对，每对一男一女, 求合法方案数(mod 1e9+7)  n<=21
const int N = 22, M = 1 << N, mod = 1e9 + 7;
int n;
int st[N][N];
int dp[N][M]; 
// st[a][b] 男a女b的配对关系
// dp[i,j] 前i个男生与女生集合j的合法配对数
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=n;j++) cin>>st[i][j];
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){ // 枚举 一维 当前第i个男生
        for(int j=1;j<(1<<n);j++){ // 枚举 二维 女生集合
            if(__builtin_popcount(j) == i){ // 男女数量相等
                for(int k=0;k<n;k++){ // 枚举 女生集合内的包含情况
                    if((j >> k) & 1 && st[i][k+1]){
                        dp[i][j] += dp[i-1][j ^ (1 << k)];
                        dp[i][j] %= mod;
                    } 
                }
            }
        }
    }
    cout << dp[n][(1<<n)-1] << "\n";
}

// 优化一维
// f[mask] 女生集合为mask,与前|mask|个男人的合法方案数  |s|求s的大小
// f[mask] = sum(f[mask - x]) (x属于mask && st[|mask|][x] == 1)
int f[M];
void solve2(){
    cin>>n;
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=n;j++) cin>>st[i][j];
    f[0] = 1;
    for(int j=1;j<(1<<n);j++){
        int i = __builtin_popcount(j);
        for(int k=0;k<n;k++){
            if((j >> k) & 1 && st[i][k+1]){
                f[j] += f[j ^ (1 << k)];
                f[j] %= mod;
            }
        }
    }
    cout << f[(1 << n) - 1] << "\n";
}

signed main(){
    srand(time(0));
    if(rand() % 2) solve();
    else solve2();
    return 0;
}
