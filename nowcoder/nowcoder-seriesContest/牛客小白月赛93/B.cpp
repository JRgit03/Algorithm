#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e6 + 10, mod = 998244353;

void solve(){
    int n; cin>>n;
    string a,b; cin>>a>>b;
    for(int i=0;i<n;i++) if(a[i] > b[i]) swap(a[i], b[i]);
    int num1 = 0, num2 = 0;
    for(auto &c : a) num1 = (num1 * 10 + (c - '0')) % mod;
    for(auto &c : b) num2 = (num2 * 10 + (c - '0')) % mod;
    cout << num1 * num2 % mod << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
