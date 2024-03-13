#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10, up = 100000;
int n;
int primes[N], cnt;
int vis[N], st[N];

void solve(){
    for(int i=2;i<=up;i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j=0;primes[j]<=up/i;j++){
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0) break; 
        }
    }    
    for(int i=0;i<cnt;i++) vis[primes[i]] = 1;
    for(int i=2;i<=up;i+=2) vis[i] = 1;
    int k = 1; while(1LL * (1 + k) * k / 2 <= up) {
        vis[1LL * (1 + k) * k / 2] = 1;
        k += 1;
    } 
    for(auto x : {1,2,5,14,42,132,429,1430,4862,16796,58786}) vis[x] = 1;
    for(int i=1;i<=up;i++) vis[i] = vis[i-1] + (vis[i] == 0);
    int x; cin>>x;
    cout << vis[x] << "\n";
}

signed main(){
    solve();
    return 0;
}
