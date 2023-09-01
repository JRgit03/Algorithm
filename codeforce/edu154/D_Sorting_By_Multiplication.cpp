#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve(){
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> pre(n+2),suf(n+2); // pre 递减  suf 递增 
    for(int i=2;i<=n;i++) pre[i] += pre[i-1] + (a[i] >= a[i-1]);
    for(int i=n-1;i>=1;i--) suf[i] += suf[i+1] + (a[i] >= a[i+1]); 
    int ans = min(pre[n]+1,suf[1]);
    for(int i=1;i<=n;i++) // 前负后正
        ans = min(ans,pre[i]+1+suf[i+1]);
    cout << ans << "\n";
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
