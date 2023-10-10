#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;
const int N = 5e3 + 10;
int n;
int a[N],dp[N]; // dp[i]表示 删完所有i的最小代价

void solve(){
    cin>>n; map<int,int> cnt;
    memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        cnt[a[i]] += 1;
    }    
    int maxx = 0;
    while(cnt.count(maxx)) maxx += 1;
    dp[maxx] = 0;
    for(int i=maxx;i;i--){ 
        for(int j=0;j<i;j++){
            dp[j] = min(dp[j],dp[i] + i * (cnt[j] - 1) + j);
        }
    }
    cout << dp[0] << "\n";
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
