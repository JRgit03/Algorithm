#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve(){
    int a,b;cin>>a>>b;
    int k = __gcd(a,b);
    if(k==1){
        cout << 1 <<"\n";
        cout<<a<<" "<<b<<"\n";
    }else{
        cout << 2 <<"\n";
        cout << 1 << " " << b-1 << "\n";
        cout << a << " " << b << "\n";
    }
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
