#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 2e3 + 10, mod = 1e9 + 7;
int m;
int c[N][N]; // c[i,j] i个物品选j个的组合方案数

void solve(){
    for(int i=0;i<=2000;i++)   
        for(int j=0;j<=i;j++)
            if(!j) c[i][j] = 1;
            else c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
    cin>>m;
    while(m--){
        int a,b; cin>>a>>b;
        cout << c[a][b] << "\n";
    }    
}

signed main(){
    IOS;
    solve();
    return 0;
}
