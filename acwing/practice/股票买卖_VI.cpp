#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n,cost;
int v[N];
int f[N][2]; // f[i,j]表示前i天第i天的状态为j j=0不持股 j=1持股
int main(){
    cin>>n>>cost;
    for(int i=1;i<=n;i++) cin>>v[i];
    memset(f,-0x3f,sizeof f);
    f[0][0] = 0;
    for(int i=1;i<=n;i++){
        f[i][0] = max(f[i-1][0],f[i-1][1]+v[i]-cost);
        f[i][1] = max(f[i-1][1],f[i-1][0]-v[i]);
    }
    cout << f[n][0] << "\n";
    return 0;
}
