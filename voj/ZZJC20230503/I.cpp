#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N][N];
int f[N][N];

int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)   
            cin>>a[i][j];
    for(int i=1;i<=n;i++)f[n][i] = a[n][i];
    for(int i=n-1;i;i--)
        for(int j=1;j<=i;j++)
            f[i][j] = max(f[i+1][j],f[i+1][j+1]) + a[i][j];
    cout << f[1][1] << "\n";    
    return 0;
}
