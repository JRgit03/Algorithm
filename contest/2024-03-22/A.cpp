#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,d; cin>>n>>d;
    int ans1 = n / d * d, ans2 = ans1 + d;
    if(n - ans1 == ans2 - n){
        cout << ans1 << "\n" << ans2 << "\n";
    }else if(n - ans1 < ans2 - n){
        cout << ans1 << "\n";
    }else{
        cout << ans2 << "\n";
    }
}

signed main(){
    solve();
    return 0;
}
