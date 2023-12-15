#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 9901;
int A,B;

int fastpow(int a,int b){
    int res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// sum(p,c) = 1 + p + p^2 + ... + p^c
int sum(int p,int c){
    if(c == 0) return 1;
    if(c & 1) return (1 + fastpow(p,(c+1)/2)) % mod * sum(p,(c-1)/2) % mod;
    return ((1 + fastpow(p,c/2)) % mod * sum(p, c/2 - 1) % mod + fastpow(p,c) % mod) % mod;  
}

signed main(){
    cin>>A>>B;
    vector<pair<int,int>> vec;
    for(int i=2;i<=A;i++){
        if(A % i == 0){
            int s = 0;
            while(A > 0 && A % i == 0) s += 1, A /= i;
            vec.push_back({i,s});
        }
    }
    if(A > 1) vec.push_back({A,1});
    int ans = 1;
    for(auto [p,c] : vec) ans = ans * sum(p,c*B%mod) % mod;
    cout << ans << "\n"; 
    return 0;
}
