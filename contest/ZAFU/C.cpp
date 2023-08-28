#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
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

signed main(){
    IOS;
    int n;cin>>n;
    map<int,int> cnt;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        cnt[x]++;
    }
    int res = 0;
    res = (res + 3 * cnt[0] * cnt[1] % Mod * cnt[2] % Mod) % Mod;
    // cout << res << "\n";
    res = (res + 2 * cnt[0] * cnt[1] % Mod * max(n - cnt[0] - cnt[1] - cnt[2],1LL*0) % Mod + 2 * cnt[0] * (cnt[0]-1) % Mod * qmi(2,Mod-2,Mod) % Mod * cnt[1] % Mod + 2 * cnt[1] * (cnt[1]-1) % Mod * qmi(2,Mod-2,Mod) % Mod * cnt[0] % Mod) % Mod;
    // cout << res << "\n";
    res = (res + cnt[0] * max(n-cnt[0]-cnt[1],1LL*0) % Mod *  max(n-cnt[0]-cnt[1]-1,1LL*0) * qmi(2,Mod-2,Mod) % Mod + (cnt[0]-1) * cnt[0] % Mod * qmi(2,Mod-2,Mod) % Mod * max(n-cnt[0]-cnt[1],1LL*0) % Mod + (cnt[0]-1) * cnt[0] % Mod * (cnt[0] - 2) % Mod* qmi(6,Mod-2,Mod) % Mod  % Mod) % Mod;
    // cout << res << "\n";
    res = res * qmi(n * (n-1) % Mod * (n-2) % Mod * qmi(6,Mod-2,Mod) % Mod,Mod-2,Mod) % Mod;
    cout << res % Mod  << "\n";
    return 0;
}
