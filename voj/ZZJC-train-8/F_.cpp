#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve(){
    int n,m;cin>>n>>m;
    int x = (m-1);
    int res = 2e9;
    
    if(n>=m){cout << n-m << "\n"; return;}
    
    for(int l=1,r;l<=n;l=r+1){
        r = min(x / (x / l) , n);
        res = min(res , x / l * l + n - m);
    }
    
    cout << res << "\n";
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
