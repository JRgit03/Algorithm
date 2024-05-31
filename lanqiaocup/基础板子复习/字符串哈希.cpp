#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e5 + 10, P = 1e9 + 7;
typedef unsigned long long ULL;
int n,m;
string s;
ULL h[N], p[N];

ULL gethash(int l,int r){
    return h[r] - h[l - 1] * p[r - l + 1];
}

void init(){
    p[0] = 1;
    for(int i=1;i<=n;i++){
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + s[i];
    }
}

void solve(){
    cin>>n>>m;
    cin>>s; s = "?" + s;
    init();
    while(m--){
        int l1,r1,l2,r2; cin>>l1>>r1>>l2>>r2;
        if(gethash(l1, r1) == gethash(l2, r2)) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
}

signed main(){
    IOS;
    solve();
    return 0;
}
