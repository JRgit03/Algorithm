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
int n;
int a[N];

int LIS(){
    vector<int> g;
    for(int i=1;i<=n;i++){
        auto it = lower_bound(g.begin(), g.end(), a[i]);
        if(it == g.end()) g.push_back(a[i]);
        else *it = a[i];
    }
    return g.size();
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cout << LIS() << "\n";    
}

signed main(){
    IOS;
    solve();
    return 0;
}
