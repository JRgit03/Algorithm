#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e8 + 10;
int n,m;
int st[N];
int primes[N], cnt;

void solve(){
    cin>>n>>m;
    for(int i=2;i<=n;i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j=0;primes[j]<=n/i;j++){
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0) break;
        }
    }
    while(m--){
        int k; cin>>k;
        cout << primes[k - 1] << "\n";
    }
}

signed main(){
    IOS;
    solve();
    return 0;
}
