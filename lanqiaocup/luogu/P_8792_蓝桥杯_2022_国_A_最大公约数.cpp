#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e5 + 10;
int n;
int a[N];

int gcd(int a,int b){
    return b ? gcd(b, a % b) : a;
}

int lg[N];
int dp[N][22];
void init(){
    for(int i=2;i<=100000;i++)lg[i] = lg[i / 2] + 1;
    for(int i=1;i<=n;i++) dp[i][0] = a[i];
    for(int j=1;j<=lg[n];j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            dp[i][j] = gcd(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
}

int ask(int l,int r){
    int len = lg[r - l + 1];
    return gcd(dp[l][len], dp[r-(1<<len)+1][len]);
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int cnt1 = 0;
    for(int i=1;i<=n;i++) cnt1 += (a[i] == 1);
    if(cnt1 > 0){
        cout << n - cnt1 << "\n";
        return;
    }
    
    init();

    if(ask(1, n) > 1){
        cout << -1 << "\n";
        return;
    }

    // 双指针,先找到最小的区间lr使得区间gcd=1,再依次更新剩下的n-1个数
    int ans = n;
    for(int l=1,r=1;r<=n;r++){
        while(l + 1 <= r && ask(l + 1, r) == 1) l += 1;
        if(l <= r && ask(l, r) == 1) ans = min(ans, r - l + 1 - 1);
    }
    ans += n - 1;
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}