#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10 ,Mod = 10007;
int a,b,k,n,m;
// c[i,j] = c[i-1,j-1] + c[i-1,j]
int c[N][N]; // c[a,b] a个里面选b个

int fastpow(int a,int b){
    int res = 1;
    while(b){
        if(b & 1) res = 1LL * res * a % Mod;
        b >>= 1;
        a = 1LL * a * a % Mod;
    }
    return res % Mod;
}

int main(){
    for(int i=0;i<=1000;i++)
        for(int j=0;j<=i;j++){
            if(!j) c[i][j] = 1;
            else c[i][j] = (c[i-1][j-1] + c[i-1][j]) % Mod;
        }
    cin>>a>>b>>k>>n>>m;
    int ans = c[k][n] * fastpow(a,n) % Mod * fastpow(b,m) % Mod;
    cout << ans << "\n";
    return 0;
}

// 二项式定理 