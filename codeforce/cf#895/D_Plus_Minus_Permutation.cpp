#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve(){
    int n,x,y; cin>>n>>x>>y;
    int num1 = n / x , num2 = n / y , num3 = n / (x * y / __gcd(x,y));
    num1 -= num3 , num2 -= num3;
    cout << (n - num1 + 1 + n) * num1 / 2- (1 + 1 + num2 - 1) * num2 / 2 << "\n";
}

signed main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
