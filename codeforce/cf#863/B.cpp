#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,a,b,c,d;cin>>n>>a>>b>>c>>d;
    if(a>n/2) a = n+1 - a;
    if(b>n/2) b = n+1 - b;
    if(c>n/2) c = n+1 - c;
    if(d>n/2) d = n+1 - d;
    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
    cout << abs(min(a,b) - min(c,d)) << "\n";
}

int main(){
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
