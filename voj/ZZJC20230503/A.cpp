#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,c;cin>>a>>b>>c;
    cout << (a+b == c ? "+" : "-") << "\n";
}

int main(){
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
