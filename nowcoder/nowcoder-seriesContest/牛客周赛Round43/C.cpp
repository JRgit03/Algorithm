#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e5 + 10;
int n;
string s;
int pre[N],suf[N];

void solve(){
    cin>>s;
    n = s.length(); s = "?" + s;
    for(int i=1;i<=n;i++) pre[i] = pre[i-1] + (s[i] >= 'a' && s[i] <= 'z');
    for(int i=n;i>=1;i--) suf[i] = suf[i+1] + (s[i] >= 'A' && s[i] <= 'Z');
    int ans = n;
    for(int i=1;i<=n-1;i++) ans = min(ans, pre[i] + suf[i+1]);
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
