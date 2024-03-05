#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e3 + 10;
int n,m;
int b[N][N];

void add(int x1,int y1,int x2,int y2){
    b[x1][y1] += 1;
    b[x2+1][y1] -= 1;
    b[x1][y2+1] -= 1;
    b[x2+1][y2+1] += 1;
}

void solve(){
    cin>>n>>m;
    while(m--) {
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        add(x1,y1,x2,y2);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cout << (b[i][j] & 1) << " \n"[j==n];
}

signed main(){
    solve();
    return 0;
}
