#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 10;
int n,m;
int a[maxn],b[maxn],c[maxn];

signed main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    for(int i=2;i<=n;i++) c[i] = abs(a[i] - a[i-1]);
    int x = n >= 2 ? c[2] : a[1];
    for(int i=3;i<=n;i++) x = __gcd(x,c[i]);
    for(int j=1;j<=m;j++) {
        if(n > 1)cout << __gcd(x,a[1]+b[j]) << " ";
        else cout << x + b[j] << " ";
    }
    return 0;
}
