#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
const int Mod = 1e9 + 7;

int fastpow(int a,int b,int p){
    int res = 1;
    while(b){
        if(b & 1) res = (res * a) % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

signed main(){
    IOS;
    int n,x,y; cin>>n>>x>>y;
    int cnt = 0;
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        cnt += (a >= x && b <= y);
    }
    cout << fastpow(2,cnt,Mod) - 1 << "\n";
    return 0;
}
