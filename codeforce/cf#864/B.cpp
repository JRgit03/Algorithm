#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 1e3 + 10;
int n,k;
int g[N][N];

void solve(){
    cin>>n>>k;
    int ne = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>g[i][j];
    for(int i=1;i<=(n+1)/2;i++)
        for(int j=1;j<=n;j++){
            if(i==n/2+1&&j>=n/2+1)break;
            ne += (g[i][j] != g[n+1-i][n+1-j]);
        }
    //cout << ne << "\n";
    cout << ((ne > k || ((k-ne)%2==1 && n%2==0)) ? "NO" : "YES") << "\n";
}

int main(){
    IOS;
    int t;cin>>t;while(t--)solve();
    return 0;
}
