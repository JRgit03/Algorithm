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
    string s; cin>>s;
    do{
        cout << s << "\n";
    }while(next_permutation(s.begin(), s.end()));
}

signed main(){
    IOS;
    solve();
    return 0;
}
