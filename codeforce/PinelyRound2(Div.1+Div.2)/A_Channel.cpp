#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve(){
    int n,on,q; cin>>n>>on>>q;
    int cnt = 0 , may = 0 , ok = 0;
    if(on == n) ok = 1;
    bool flag = false;
    for(int i=0;i<q;i++){
        char c; cin>>c;
        may += c == '+';
        cnt += c == '+';
        cnt -= c == '-';
        if(cnt + on >= n) ok = 1;
        if(may + on >= n) flag |= 1;
    }
    if(ok) cout << "YES" << "\n";
    else cout << (flag ? "MAYBE" : "NO") << "\n";
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--) solve();
    return 0;
}
