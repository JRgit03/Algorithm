#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e6 + 10;
int n,m;
string str;
string s[N];
string dp[N]; // 最长上升子序列数组
string ans[N]; // ans[i]表示 长度为i的ans

void solve(){
    cin>>str; m = str.length();
    for(int i=0;i<m;i++){
        int j = i + 1; s[++n] += str[i]; 
        while(j < m && str[j] >= 'a' && str[j] <= 'z') {
            s[n] += str[j]; j += 1;
        } 
        i = j - 1;
    } 
    int len = 0; // 最长上升子序列最大长度len
    for(int i=1;i<=n;i++){
        int pos = lower_bound(dp + 1, dp + len + 1, s[i]) - dp;
        len = max(len, pos);
        dp[pos] = s[i];
        ans[pos] = ans[pos - 1] + s[i];
    }
    cout << ans[len] << "\n";     
}

signed main(){
    IOS;
    solve();
    return 0;
}
