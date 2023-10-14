#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int a[N],dp[N];

void solve(){
    int n; cin>>n;
    dp[n+1] = 0;
    for(int i=1;i<=n;i++) dp[i] = n-i+1;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>=1;i--){
        if(i+a[i] <= n){
            dp[i] = min(dp[i],dp[i+a[i]+1]);
        }
        dp[i] = min(dp[i],dp[i+1]+1);
    }
    cout << dp[1] << "\n";
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
