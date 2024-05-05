#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define SETPRECISION cout << fixed << setprecision(10);
#define int long long
#define fi first
#define se second
using namespace std;

#ifdef LOCAL
#include "../../algorithm-template/debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e3 + 10, M = 1e5 + 10, mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
typedef pair<int,int> PII;
typedef long long ll;

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int n,m,up;
string s,t;
int f[N][27]; // f[i,j] 第i个字母为起点左边最近的字母j的位置
int g[N][26]; // f[i,j] 第i个字母为起点右边最近的字母j的位置
// int dp[M][N]; // dp[i,j] 匹配T字符串的前i字母且以S字符串的第j个字母结尾的最小代价
int dp[2][N]; // 滚动数组优化

void solve(){
    cin>>n>>m>>up;
    cin>>s>>t; s = "?" + s; t = "$" + t;
    memset(dp, 0x3f, sizeof dp);
    for(int i=0;i<=n;i++)
        for(int j=0;j<26;j++){
            f[i][j] = 0;
            g[i][j] = n+1;
        }
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++) 
            f[j][s[i]-'a'] = max(f[j][s[i]-'a'], i); 
    for(int i=n;i>=1;i--)
        for(int j=i;j>=1;j--) 
            g[j][s[i]-'a'] = min(g[j][s[i]-'a'], i); 
    int ans = 0;
    for(int j=1;j<=n;j++) if(s[j] == t[1]) {
        ans = 1;
        dp[1][j] = 0;
    }
    for(int i=2;i<=m;i++){
        int cur = i & 1, pre = cur ^ 1;
        for(int j=1;j<=n;j++){
            if(s[j] == t[i]){
                if(f[j][t[i-1]-'a'] != 0) dp[cur][j] = min(dp[cur][j], dp[pre][f[j][t[i-1]-'a']] + abs(j - f[j][t[i-1]-'a']));
                if(g[j][t[i-1]-'a'] != n+1) dp[cur][j] = min(dp[cur][j], dp[pre][g[j][t[i-1]-'a']] + abs(j - g[j][t[i-1]-'a']));
            }
            if(dp[cur][j] != INF && dp[cur][j] <= up) ans = i;
            debug(i,j,dp[cur][j]);
        }
        for(int j=1;j<=n;j++) dp[pre][j] = INF; // 清空上一层 否则会对后续dp造成影响
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    int T=1;
    // cin>>T;
    while(T--)
        solve();
    return 0;
}
