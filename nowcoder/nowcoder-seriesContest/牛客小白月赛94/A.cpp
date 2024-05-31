#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 11;
char a[N];

void solve(){
    for(int i=1;i<=9;i++) cin>>a[i];
    string s; cin>>s;
    string ans = "";
    for(auto &c : s) ans += a[c - '0'];
    cout << ans << "\n";   
}

signed main(){
    IOS;
    solve();
    return 0;
}
