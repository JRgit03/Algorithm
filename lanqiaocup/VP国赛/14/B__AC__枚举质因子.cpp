#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e7 + 10, up = 1e7;
int primes[N],cnt;
int st[N];

void solve(){
    int l = 2333, r = 23333333333333; 
    int n = sqrt(r); debug(n); 
    for(int i=2;i<=n;i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j=0;primes[j]<=n/i;j++){
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0) break;
        }
    }    
    debug(cnt);
    int ans = 0;
    for(int i=0;i<cnt;i++){
        for(int j=i+1;j<cnt;j++){
            int x = primes[i], y = primes[j];
            __int128 v = (__int128)x * x * y * y; // 947293 AC
            // __int128 v = x * x * y * y; 947303 错误 x * x * y * y 会溢出long long
            if(v > r) break;;
            if(v < l) continue;
            ans += 1;
        }
    }
    cout << ans << "\n"; // 947293
}

signed main(){
    IOS;
    solve();
    return 0;
}
