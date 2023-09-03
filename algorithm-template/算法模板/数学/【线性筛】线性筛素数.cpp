#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;
const int N = 1e8 + 10;
int primes[N] , cnt;
int st[N];

void get_primes(int n){
    for(int i=2;i<=n;i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j=0;primes[j]<=n/i;j++){
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0) break;
        }
    }
}

void solve(){
    int n,m; cin>>n>>m;
    get_primes(n);
    while(m--) {
        int k; cin>>k;
        cout << primes[k-1] << "\n";
    }
} 

int main(){
    IOS; solve();
    return 0;
}
