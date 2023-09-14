#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
typedef long long ll;
const int N = 2;
int n,Mod;

struct matrix {
    int m[N][N];
};

matrix operator * (const matrix &a , const matrix &b){
    matrix c; memset(c.m , 0 , sizeof c.m);
    for(int k=0;k<N;k++)
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                    c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]) % Mod;
    return c;
}

matrix fastpow(matrix a, int n){
    matrix ans; memset(ans.m , 0 , sizeof ans.m);
    for(int i=0;i<N;i++) ans.m[i][i] = 1;
    while(n){
        if(n & 1) ans = ans * a;
        a = a * a;
        n >>= 1;
    }
    return ans;
}

void solve(){
    cin>>n>>Mod;
    if(n <= 2) cout << 1 % Mod << "\n";
    else{
        matrix a; memset(a.m,0,sizeof a.m); 
        a.m[0][0] = a.m[0][1] = a.m[1][0] = 1;
        a = fastpow(a,n-2);
        int b[1][2]; memset(b , 0 , sizeof b); b[0][0] = b[0][1] = 1;
        int c[1][2]; memset(c , 0 ,sizeof c);
        for(int k=0;k<2;k++){
            for(int i=0;i<1;i++){
                for(int j=0;j<2;j++){
                    c[i][j] = (c[i][j] + b[i][k] * a.m[k][j]) % Mod;
                }
            }
        }
        cout << c[0][0] << "\n";
    }
}

signed main(){
    IOS; solve();
    return 0;
}
