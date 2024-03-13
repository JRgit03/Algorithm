#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100010;
const int mod = 1e9 + 7;
int fact[N] , infact[N];

int qmi(int a , int k ,int p){
    int res = 1;
    while(k){
        if(k&1) res = 1LL * res * a % p;
        a = 1LL *a* a % p;
        k >>= 1;
    }
    return res;
} 

int C(int a,int b){
    return 1LL * fact[a] * infact[a-b] % mod * infact[b] % mod;
}

void solve(){
    fact[0] = infact[0] = 1;
    for(int i=1;i<=100000;i++){
        fact[i] = 1LL * fact[i-1] * i % mod;
        infact[i] = 1LL * infact[i-1] *  qmi(i,mod-2,mod) % mod;
    }
    for(int i=1;i<=40;i++) cout << C(2*i, i) / (i + 1) << "\n";
}

signed main(){
    solve();
    return 0;
}


