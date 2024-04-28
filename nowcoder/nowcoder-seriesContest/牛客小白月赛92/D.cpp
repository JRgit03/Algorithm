#include <bits/stdc++.h>
#define int long long
using namespace std;

#ifdef LOCAL
#include "../algorithm-template/debug.h"
#else
#define debug(...) 42
#endif

void solve(){
    int n; cin>>n;
    int s1 = 0, s2 = 0, s3 = 0;
    for(int i=1;i<=n;i++){
        int v; cin>>v;
        s1 += i * i * v;
        s2 += v;
        s3 += 2 * i * v;
    }
    int ans = LONG_LONG_MAX;
    for(int x=1;x<=n;x++) ans = min(ans, s1 + s2 * x * x - s3 * x);
    cout << ans << "\n";
}

signed main(){
    solve();
    return 0;
}
