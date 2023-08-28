#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10 , zero = 0;
int n,m,b;
int a[N];
int f[N][2];

signed main(){
    cin>>n>>m>>b;
    for(int i=1;i<=n;i++) cin>>a[i] , a[i] += a[i-1];
    for(int i=1;i<=n;i++){
        f[i][0] = f[i-1][0];
        f[i][1] = max(f[i-1][0],f[max(i-m,zero)][1] + min(b,a[i]-f[max(i-m,zero)][1]));
    }
    cout << max(f[n][0],f[n][1]) << "\n";
    return 0;
}
