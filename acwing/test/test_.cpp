#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n,m;
int f[N][N]; //f[i,j]表示考虑前i个字母,是否能走到状态j

int main(){
    string s,p;cin>>s>>p;
    n = s.length() , m = p.length();
    s = "?" + s , p = "@" + p;
    f[0][0] = 1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=m;j++){
            f[i][j] = f[i-1][j];
            if(s[i] == p[j]) f[i][j] |= f[i-1][j-1];
        }
    
    return 0;
}
