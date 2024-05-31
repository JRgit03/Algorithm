#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 2e5 + 10;
int n,m;
int a[N];

int lg[N];
int dp[N][21];
void init(){
    for(int i=2;i<=n;i++) lg[i] = lg[i / 2] + 1;
    for(int i=1;i<=n;i++) dp[i][0] = a[i];
    for(int j=1;j<=lg[n];j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            dp[i][j] = max(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
}
int query(int l,int r){
    int len = lg[r - l + 1];
    return max(dp[l][len], dp[r-(1<<len)+1][len]);
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    init();
    cin>>m;
    while(m--){
        int l,r; cin>>l>>r;
        cout << query(l, r) << "\n";
    }
}

signed main(){
    IOS;
    solve();
    return 0;
}
