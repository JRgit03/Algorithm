#include <bits/stdc++.h>
using namespace std;
const int N = 210 , M = 1e4 + 10;
int colors,n,m;
int a[N],b[M];
int f[N][M];

int main(){
    cin>>colors;
    cin>>n;for(int i=1;i<=n;i++)cin>>a[i];
    cin>>m;for(int i=1;i<=m;i++)cin>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            f[i][j] = max(f[i-1][j],f[i][j-1]);
            if(a[i]==b[j]) f[i][j] = max(f[i][j],f[i][j-1]+1); //与最长公共子序列的不同点  ->  a对b可以一对多
        }    
    cout << f[n][m] << "\n";
    return 0;
}
