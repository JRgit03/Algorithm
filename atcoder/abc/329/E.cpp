#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n,m;
string s,t;

int dp[maxn][10]; // dp[i,j] 表示前i个字符与s[1~i]匹配且以t[j]结尾

int main(){
    cin>>n>>m>>s>>t; s = "?" + s; t = "&" + t;
    dp[1][1] = (s[1] == t[1]);
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!dp[i-1][j]) continue;
            if(s[i] == t[1]) dp[i][1] = 1;
            if(j+1<=m && s[i] == t[j+1]) dp[i][j+1] = 1;
            if(j == m) {
                for(int k=1;k<=m;k++){
                    if(s[i] == t[k]){
                        dp[i][k] = 1;
                    }
                }
            }
        }
    } 
    cout << (dp[n][m] ? "Yes" : "No") << "\n";
    return 0;
}
