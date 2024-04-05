#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b) {return (a > b ? a : b);}
int min(int a,int b) {return (b > a ? a : b);}

int d[8][8];

void init(){
    memset(d, 0x3f, sizeof d);
    for(int i=1;i<=7;i++) d[i][i] = 0;
    vector<pair<int,int>> edges = {{1,2},{1,3},{2,4},{3,4},{4,5},{4,6},{5,7},{6,7}};
    for(auto [u,v] : edges) d[u][v] = d[v][u] = 1;
    for(int k=1;k<=7;k++)
        for(int i=1;i<=7;i++)
            for(int j=1;j<=7;j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

void solve(){
    int a1,a2,b1,b2; cin>>a1>>a2>>b1>>b2;
    int ans1 = d[a1][b1] + d[a2][b2], ans2 = d[a1][b2] + d[a2][b1];
    cout << min(ans1, ans2) << "\n";
}

signed main(){
    IOS;
    init();
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
