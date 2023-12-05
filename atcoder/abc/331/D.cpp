#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e3 + 10;
int n,q;
string g[maxn];
int s[maxn][maxn];

int f(int x,int y){
    if(x <= n && y <= n) return s[x][y];
    int res = 0;
    res += (x / n) * (y / n) * s[n][n];
    res += x / n * s[n][y%n];
    res += y / n * s[x%n][n];
    res += s[x%n][y%n];
    return res;
}

signed main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>g[i], g[i] = "?" + g[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            s[i][j] = (g[i][j] == 'B');
            s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
        }
    while(q--){
        int a,b,c,d; cin>>a>>b>>c>>d; a++,b++,c++,d++;
        cout << f(c,d) - f(c,b-1) - f(a-1,d) + f(a-1,b-1) << "\n";
    }
    return 0;
}
