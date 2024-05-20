#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e6 + 10;

void solve(){
    int n; cin>>n;
    if(n & 1) cout << -1 << "\n";
    else cout << n/2 << " " << n/2 << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
