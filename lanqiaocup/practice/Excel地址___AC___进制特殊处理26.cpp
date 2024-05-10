#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e6 + 10;

void solve(){
    int n; cin>>n;
    string ans = "";
    while(n > 0){
        if(n % 26 != 0){
            ans.push_back(char(n % 26 + 'A' - 1));
            n /= 26;
        }else{
            ans.push_back('Z');
            n /= 26;
            n -= 1;
        }
    } 
    debug(ans);
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
