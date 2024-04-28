#include <bits/stdc++.h>
#define int long long
using namespace std;

#ifdef LOCAL
#include "../algorithm-template/debug.h"
#else
#define debug(...) 42
#endif

void solve(){
    int n; cin>>n;
    vector<int> a(n); for(auto &x : a) cin>>x;
    int x; cin>>x;
    vector<int> cnt(32);
    for(int i=0;i<n;i++){
        int v = a[i], a = 1, b = 0; cin>>v;
        while(v >= x){
            if(v == x) cnt[b] += a;
            v = (v + 3 - 1) / 3;
            b += 1;
            a = a * 2;
        }
    }
    cout << *max_element(cnt.begin(), cnt.end()) << "\n";
}

signed main(){
    solve();
    return 0;
}
