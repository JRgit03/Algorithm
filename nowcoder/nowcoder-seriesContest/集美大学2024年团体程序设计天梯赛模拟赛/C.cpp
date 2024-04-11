#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    double r1,r2; cin>>r1>>r2;
    double pi = acos(-1);
    cout << fixed << setprecision(6) << pi * (r2 * r2 - r1 * r1) << "\n";
}

signed main(){
    solve();
    return 0;
}
