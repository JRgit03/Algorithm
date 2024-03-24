#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m; cin>>n>>m;
    double p,q; cin>>p>>q; p /= 100; q /= 100;
    double ans = n / m;
    int k = n / m;
    double qm = 1.0;
    for(int i=1;i<=m;i++) qm = qm * q;
    qm = qm + qm * p;
    if(p * m >= qm) ans += p * k;
    else{
        ans += 
    }
}

signed main(){
    solve();
    return 0;
}
