#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 10 , Mod = 998244353;
int n,x;
int t[N];
int dp[N]; // dp[i]表示歌曲在第i秒播放的概率 (不一定是第一首歌)

int fastpow(int a,int b){
    int res = 1;
    while(b){
        if(b&1) res = 1LL * res * a % Mod;
        b >>= 1;
        a = 1LL * a * a % Mod;
    }
    return res;
}

int inv(int x){
    return fastpow(x,Mod-2);
}

signed main(){
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>t[i];
    dp[0] = 1; int base = inv(n);
    for(int i=1;i<=x;i++){
        for(int j=1;j<=n;j++){
            if(i-t[j]>=0){
                dp[i] = (dp[i] + dp[i-t[j]] * base) % Mod; 
            }
        }
    }
    int ans = 0;
    for(int i=max(0LL,x-t[1]+1);i<=x;i++) ans = (ans + dp[i]) % Mod;
    cout << (ans * base) % Mod << "\n"; 
    return 0;
}

//最终的答案之和为 歌曲1在 x-t[i]+1~x 之间概率之和 指定歌曲所以 * 1/n