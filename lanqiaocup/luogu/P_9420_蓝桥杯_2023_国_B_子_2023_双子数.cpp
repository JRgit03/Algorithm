#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

void solveA(){
    string s = "", p = "$2023";
    for(int i=1;i<=2023;i++) s += to_string(i);
    int n = s.length(); s = "?" + s;
    int dp[n+1][5]; memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=4;j++) dp[i][j] = dp[i-1][j];
        if(s[i] == '2') {
            dp[i][1] += dp[i-1][0];
            dp[i][3] += dp[i-1][2];
        }else if(s[i] == '0'){
            dp[i][2] += dp[i-1][1];
        }else if(s[i] == '3'){
            dp[i][4] += dp[i-1][3];
        }
    }
    cout << dp[n][4] << "\n";
}


const int N = 1e7 + 10;
int primes[N], cnt;
int st[N];

void solveB(){
    int l = 2333, r = 23333333333333;
    // cout << sqrt(r) << "\n"; // 4.8e6
    // cout << 1LL * 256 * 1024 * 1024 * 8 / 64 << "\n"; 3e7
    int n = sqrt(r) + 1;
    for(int i=2;i<=n;i++){  // 质数从2开始!
        if(!st[i]) primes[cnt++] = i;
        for(int j=0;primes[j]<=n/i;j++){
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0) break;
        }
    }
    int ans = 0;
    for(int i=0;i<cnt;i++){
        for(int j=i+1;j<cnt;j++){
            int x = primes[i], y = primes[j];
            __int128 v = (__int128) x * x * y * y;
            if(v > r) break;
            if(v >= l) ans += 1;
        }
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    char c; cin>>c;
    if(c == 'A') solveA();
    else solveB();
    return 0;
}
