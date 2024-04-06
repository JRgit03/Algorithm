#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n; cin>>n;
    for(int i=1;i<=n;i++){
        if(i % 3 == 0) cout << "x";
        else cout << "o";
    }
}

signed main(){
    solve();
    return 0;
}
