#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll b; cin>>b;
    for(ll i=1;;i++){
        ll x = 1;
        ll f = 0;
        for(ll j=0;j<i;j++){
            if((__int128)(x*i) > 1e18){
                f = 1;
                break;
            } 
            x *= i;
        }
        if(f)break;
        if(x == b) {
            cout << i << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}
