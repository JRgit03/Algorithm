// https://www.luogu.com.cn/problem/P2034
// 单调队列优化dp
// 题意：给定n个非负正数a1..an,可选若干数,但不能有超过k个连续数字被选
//      要求 选出的数字和最大！ n <= 1e5, ai <= 1e9
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n,k;
int a[N],s[N];
int dp[N][2],q[N];

// dp[i,0/1] 表示前i个数且以ai结尾 选或不选 的 被选数字最大之和
// dp[i][0] = max(dp[i-1][0], dp[i-1][1])
// dp[i][1] = max(dp[i-1][0])
// dp[i][1] = max{ dp[j][0] + sum[j+1~i] }, 0 <= i-k <= j < i  sum[l,r] 区间和
// O(n^2)复杂度考虑优化
// => dp[i][1] = max{ dp[j][0] - s[j] + s[i] }   s前缀和数组
// => dp[i][1] = max{ dp[j][0] - s[j] } + s[i]  s[i]常数项
// 考虑 单调队列优化 dp转移 维护 dp[j][0] - s[j] 非严格单调递减队列 存下标
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i]; s[i] = s[i-1] + a[i];
    } 
    int l = 1, r = 0;
    q[r++] = 0; // 单调队列初始化 首个元素应该为{dp[0][0] - s[0]}
    for(int i=1;i<=n;i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        while(l <= r && i - q[l] > k) l += 1;
        while(l <= r && dp[q[r]][0] - s[q[r]] < dp[i][0] - s[i]) r -= 1;
        q[++r] = i;
        dp[i][1] = dp[q[l]][0] - s[q[l]] + s[i];
    }
    cout << max(dp[n][1], dp[n][0]) << "\n";
}

signed main(){
    solve();
    return 0;
}
