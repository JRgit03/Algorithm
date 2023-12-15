#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

int n,m;
string s;

int C[505][505];
int ans[26][26][500];

signed main(){
    memset(C,0,sizeof C);
    for(int i=0;i<=500;i++)
        for(int j=0;j<=i;j++)
            if(!j) C[i][j] = 1;
            else C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
    cin>>n>>s; s = "?" + s;
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
            for(int k=0;k<=i-j-1;k++){  
                ans[s[j]-'a'][s[i]-'a'][k] += C[i-j-1][k];
                ans[s[j]-'a'][s[i]-'a'][k] %= mod;
            }
    cin>>m; while(m--){
        char c1,c2; int len; cin>>c1>>c2>>len; len -= 2;
        cout << ans[c1-'a'][c2-'a'][len] << "\n";
    }
    return 0;
}
