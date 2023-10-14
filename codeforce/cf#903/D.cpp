#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int primes[N],cnt;
bool st[N];
int minP[N];

void get_primes(int n){
	memset(minP,0x3f,sizeof minP);
    for(int i=2;i<=n;i++){
        if(!st[i]) primes[cnt++] = i, minP[i] = i;;
        for(int j=0;primes[j]<=n/i;j++){
            st[primes[j] * i] = true;
            minP[primes[j] * i] = min(minP[primes[j] * i],primes[j]);
            if(i % primes[j] == 0){
                minP[i] = primes[j]; break;
            }
        } 
    }
}

void solve(){
    int n; cin>>n;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        while(x > 1){
            mp[minP[x]] += 1;
            // cout << minP[x] << "\n";
            x /= minP[x];
        }
    }
    int f = 1;
    for(auto [x,cnt] : mp) f &= ((cnt % n) == 0);
    cout << (f ? "YES" : "NO") << "\n";
}

int main(){
    IOS; 
    get_primes(1000000);
    // cout << minP[1000000] << "\n";
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
