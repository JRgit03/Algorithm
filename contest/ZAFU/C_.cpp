#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Mod = 998244353;

int qmi(int m,int k,int p){
    int res = 1 % p , t = m;
    while(k){
        if(k&1) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;
}

int n,cnt0,cnt1,cnt2,cnt3;

signed main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(x==0)cnt0++;
        else if(x==1)cnt1++;
        else if(x==2)cnt2++;
        else if(x==3)cnt3++;
    }
    int res = 0 , zero = 0;
    res = (res + 1 * cnt0 * max(n-cnt0-cnt1,zero) % Mod * max(n-cnt0-cnt1-1,zero) % Mod * qmi(2,Mod-2,Mod) % Mod + 1 * cnt0 * (cnt0 - 1) % Mod * qmi(2,Mod-2,Mod) % Mod * max(n-cnt0-cnt1,zero) % Mod + 1*cnt0*(cnt0-1)%Mod*(cnt0-2)%Mod*qmi(6,Mod-2,Mod)%Mod) % Mod;
    // cout << res << "\n";
    res = (res + 2 * cnt0 * cnt1 % Mod * max(n-cnt0-cnt1-cnt2,zero) % Mod + 2 * cnt0 * (cnt0-1) % Mod * qmi(2,Mod-2,Mod) % Mod * cnt1 % Mod + 2 * cnt1 * (cnt1-1) % Mod * qmi(2,Mod-2,Mod) % Mod * cnt0 % Mod )%Mod;
    // cout << res << "\n";
    res = (res + 3 * cnt0 * cnt1 % Mod * cnt2 % Mod) % Mod;
    // cout << res << "\n";
    res = res * qmi(n * (n-1) % Mod * (n-2) % Mod * qmi(6,Mod-2,Mod) % Mod,Mod-2,Mod) % Mod;
    cout << res % Mod  << "\n";
    return 0;
}
