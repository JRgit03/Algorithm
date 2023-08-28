#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve(){
    ll n,k;cin>>n>>k;
    if(!(k&1)){
        cout << (n%2==0 ? "YES" : "NO") << "\n";
    }else{
        cout << (n>=k ? "YES" : "NO") << "\n";
    }
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
