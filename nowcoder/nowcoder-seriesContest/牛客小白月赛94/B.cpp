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
int n;
int a[N];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int f = 0, maxx = a[1];
    for(int i=2;i<=n;i++){
        f |= (a[i] < maxx);
        maxx = max(maxx, a[i]);
    }
    cout << (f ? n : 0);
}

signed main(){
    IOS;
    solve();
    return 0;
}
