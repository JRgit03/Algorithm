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

int gcd(int a,int b){
    return b ? gcd(b, a % b) : a;
}

void solve(){
    int m; cin>>m;
    while(m--){
        int a,b; cin>>a>>b;
        cout << gcd(a, b) << "\n";
    }
}

signed main(){
    IOS;
    solve();
    return 0;
}
