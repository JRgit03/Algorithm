#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

int fastpow(int a,int b,int Mod){
    int res = 1;
    while(b){
        if(b&1) res = 1LL * res * a % Mod;
        a = 1LL * a * a % Mod;
        b >>= 1;
    }
    return res;
}

int main(){
    IOS;
    int a,b,Mod;cin>>a>>b>>Mod;
    printf("%d^%d mod %d=%d",a,b,Mod,fastpow(a,b,Mod));
    return 0;
}
