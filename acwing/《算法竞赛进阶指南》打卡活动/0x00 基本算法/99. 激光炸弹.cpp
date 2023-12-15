#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 10;
int n,r;
int x[maxn],y[maxn];
int f[maxn][maxn];

int main(){
    cin>>n>>r;
    for(int i=0;i<n;i++){
        int u,v,w; cin>>u>>v>>w; u++,v++;
        f[u][v] += w;
    }
    for(int i=1;i<=5001;i++)
        for(int j=1;j<=5001;j++)
            f[i][j] += f[i-1][j] + f[i][j-1] - f[i-1][j-1];
    int ans = 0;
    for(int i=1;i<=5001;i++)
        for(int j=1;j<=5001;j++){
            int a = max(5001,i + r - 1), b = max(5001,j + r - 1);
            ans = max(ans, f[a][b] - f[i-1][b] - f[a][j-1] + f[i-1][j-1]);
        }
    cout << ans << "\n";
    return 0;
}
