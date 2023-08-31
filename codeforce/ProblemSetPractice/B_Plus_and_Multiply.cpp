#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

// x = a^i + j*b
void solve(){
    int n,a,b; cin>>n>>a>>b;
    if(b == 1){
        cout << "Yes" << "\n";
        return;
    }
    if(a == 1){
        cout << ((n-1)%b == 0 ? "Yes" : "No") << "\n";
        return;
    }
    int powa = 1;
    while(powa <= n){
        if((n - powa) % b == 0){
            cout << "Yes" << "\n";
            return;
        }
        powa = powa * a;
    }
    cout << "No" << "\n";
    return;
}
signed main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
