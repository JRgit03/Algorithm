#include <bits/stdc++.h>
#define int long long
using namespace std;
// 题意：
// 有一排花，共 n 个，第 i 个的高度是 ℎi,权值是 ai，
// 保证高度互不相同。现在拿走一些花，使剩下的花高度单调递增，问剩下的花权值之和最大是多少。
const int N = 2e5 + 10;
int n;
int h[N], val[N];
int dp[N]; 
// dp[i] 表示以下标i结尾的最大化权值之和
// dp[i] = dp[j] + val[i] (j < i, h[j] < h[i])
// 查询区间 1~h[i]-1的最大值dp[j]

int a[N],tr[N];
int lowbit(int x){ return x&-x;}
int getmax(int l,int r){
    int ans = 0;
    while(l <= r){
        ans = max(ans,a[r]);
        r--;
        for(;r-lowbit(r)>=l;r-=lowbit(r)) 
            ans = max(ans, tr[r]);
    }
    return ans;
}
void update(int x,int v){
    a[x] = v;
    for(int i=x;i<=n;i+=lowbit(i)){
        tr[i] = a[i];
        for(int j=1;j<lowbit(i);j*=2)
            tr[i] = max(tr[i],tr[i-j]);
    }
} 

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>h[i];
    for(int i=1;i<=n;i++) cin>>val[i];
    int ans = 0;
    for(int i=1;i<=n;i++){
        dp[i] = getmax(1, h[i]-1) + val[i];
        update(h[i], dp[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}


signed main(){
    solve();
    return 0;
}
