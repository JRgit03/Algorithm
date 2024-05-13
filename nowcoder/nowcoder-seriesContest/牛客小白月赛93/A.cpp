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
    int n,a,k; cin>>n>>a>>k;
    int x = a + 1;
    while(k--){
        if(x % 7 != 0 && to_string(x).find('7') == -1) cout << x << " ";
        else cout << "p" << " ";
        x += n;
    }
    cout << "\n";
}

signed main(){
    IOS;
    int t; cin>>t;
    while(t--)
        solve();
    return 0;
}
