#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    string p = "PER"; 
    string s; cin>>s;
    int ans = 0;
    for(int i=0,j=0;i<s.length();i++){
        ans += (s[i] != p[j]);
        j = (j + 1) % 3;
    }
    cout << ans << "\n";
}

signed main(){
    solve();
    return 0;
}
