#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e6 + 10;
int n,k;
// https://zhuanlan.zhihu.com/p/121159246
// 证明：考虑第一个人出去后，问题变成 𝑛−1个人，𝑘次一出的约瑟夫问题
// dp[i,k] 表示i个人,k次一出的约瑟夫环问题
// dp[i,k] = (dp[i-1][k] + k) % i
int dp[N];
void solve(){
    cin>>n>>k;
    dp[1] = 0;
    for(int i=2;i<=n;i++){
        dp[i] = (dp[i - 1] + k) % i;
    }    
    cout << dp[n] + 1 << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}

// 解决约瑟夫环问题，我们采用倒推，我们倒推出：最后剩下的这个数字，在最开始的数组中的位置。
