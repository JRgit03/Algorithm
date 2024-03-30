#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int C,n; cin>>C>>n;
    int suc = 1, s = 0;
    for(int i=0;i<n;i++){
        int a,b,c; cin>>a>>b>>c;
        s -= a;
        if(s < 0) suc = 0;
        s += b;
        if(s > C) suc = 0;
        if(C - s > 0 && c > 0) suc = 0;
    }
    if(s != 0) suc = 0;
    cout << (suc ? "possible" : "impossible") << "\n";
}

signed main(){
    solve();
    return 0;
}
