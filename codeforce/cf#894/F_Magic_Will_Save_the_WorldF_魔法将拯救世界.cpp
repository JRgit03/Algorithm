#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

// 0 1 背包合法方案 exist
void solve(){
    int w,f; cin>>w>>f;
    int n,m; cin>>n; m = n * 10000 + 1;
    vector<int> s(n+1),dp(m); 
    int sum = 0; dp[0] = 1;
    for(int i=1;i<=n;i++) cin>>s[i] , sum += s[i];
    for(int i=1;i<=n;i++){
        for(int j=m;j>=s[i];j--){
            dp[j] |= dp[j-s[i]];
        }
    }
    int ans = INT_MAX;
    for(int i=0;i<=sum;i++)
        if(dp[i]){
            ans = min(ans,max((i+w-1)/w,(sum-i+f-1)/f));
        }
    cout << ans << "\n";
}

int main(){
	IOS;
	int t;cin>>t;
    while(t--)solve();
	return 0;
}