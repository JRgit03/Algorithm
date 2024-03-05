#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10, mod = 1e9 + 7;
int n;
int fact[N], infact[N];

int fastpow(int a,int b){
    int res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res % mod;
}

int C(int a,int b){
    return fact[a] * infact[a - b] % mod * infact[b] % mod;
}

signed main(){
    fact[0] = infact[0] = 1;
    for(int i=1;i<N;i++){
        fact[i] = fact[i-1] * i % mod;
        infact[i] = infact[i-1] * fastpow(i, mod - 2) % mod;
    }
    cin>>n;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for(int i=1;i<=n;i++) {
        int x; cin>>x;
        (x == 1 ? cnt1 += 1 : (x == 2 ? cnt2 += 1 : cnt3 += 1));
    }
    int s1 = fastpow(2, cnt1), s2 = 0, s3 = 0;
    for(int i=0;i<=cnt2;i++) s2 += (i + 1) * C(cnt2, i), s2 %= mod;
    for(int i=0;i<=cnt3;i++) s3 += (i + 1) * C(cnt3, i), s3 %= mod;
    cout << ((s1 * s2 % mod * s3 % mod - 1) % mod + mod) % mod   << "\n"; 
    return 0; 
}

// 单独 考虑各个部分的贡献  选或不选的所有的可能相乘 - 1(所有不选的情况)
