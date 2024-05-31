#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e3 + 10;
int n,m;
string s,t;
int dp[N]; //dp[i]字符串s匹配字符串t前i个字符的方案是否存在

void solve(){
    cin>>s>>t;
    n = s.length(), m = t.length();
    s = "?" + s; t = "$" + t;
    dp[0] = 1;
    for(int i=1;i<=n;i++)
        for(int j=m;j>=1;j--)
            if(s[i] == t[j]){
                dp[j] |= dp[j-1];
            }
    int ans = 0;
    for(int j=1;j<=m;j++) if(dp[j]) {
        ans = j;
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
