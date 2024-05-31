#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 3e5 + 10, INF = 0x3f3f3f3f3f3f3f3f;
int n,m;
int a[N];
int s[N];
int q[N],hh,tt;

// dp[i] 表示以ai为结尾长度不超过m的连续子序列最大值
// dp[i] = max(s[i] - s[j-1]) (i - m + 1 <= j <= i)
// dp[i] = s[i] - min(s[j-1]) 单调队列维护区间最小值

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i]; s[i] = s[i - 1] + a[i];
    }    
    int ans = -INF; hh = 0, tt = -1; q[++tt] = 0;
    for(int i=1;i<=n;i++){
        while(hh <= tt && i - q[hh] > m) hh += 1; // [l-1, r]
        ans = max(ans, s[i] - s[q[hh]]);
        while(hh <= tt && s[q[tt]] >= s[i]) tt--;
        q[++tt] = i;
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
