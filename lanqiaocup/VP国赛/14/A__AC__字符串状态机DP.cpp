#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e6 + 10;
string s = "";
int dp[4];

void solve(){
    s = "";
    for(int i=1;i<=2023;i++) s += to_string(i);
    int n = s.length(); debug(n); 
    for(int i=1;i<=n;i++){
        char c = s[i-1];
        if(c == '2') {
            dp[0] += 1;
            dp[2] += dp[1];
        }else if(c == '0'){
            dp[1] += dp[0];
        }else if(c == '3'){
            dp[3] += dp[2];
        }
    }
    cout << dp[3] << "\n"; // 5484660609
}

string t = "2023";
int f[N][5]; // f[i,j] 前i个字符匹配到状态j的个数
void solve2(){
    s = "";
    for(int i=1;i<=2023;i++) s += to_string(i);
    int n = s.length(); debug(n); 
    f[0][0] = 1;
    for(int i=1;i<=n;i++){
        char c = s[i-1];
        for(int j=0;j<=4;j++) f[i][j] = f[i-1][j];
        if(c == '2') {
            f[i][1] += f[i-1][0];
            f[i][3] += f[i-1][2];
        }else if(c == '0'){
            f[i][2] += f[i-1][1];
        }else if(c == '3'){
            f[i][4] += f[i-1][3];
        }
    }
    cout << f[n][4] << "\n"; // 5484660609
}

signed main(){
    IOS;
    //solve();
    solve2();
    return 0;
}
