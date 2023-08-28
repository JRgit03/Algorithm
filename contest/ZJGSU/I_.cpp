#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

const int Mod = 998244353;

int qmi(int m,int k,int p){
    int res = 1 , t = m;
    while(k){
        if(k&1) res = res * t % p;
        t = t*t % p;
        k >>= 1;
    }
    return res;
}

signed main(){
    IOS;
    int t;cin>>t;while(t--){
        int n;cin>>n;
        cout << (qmi(2,n-1,Mod) * n) % Mod << "\n";
    }
    return 0;
}
