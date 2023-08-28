#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve(){
    int n;cin>>n;
    vector<vector<int> > v(2,vector<int>(n+1));
    v[0][1] = n*2 , v[1][n] = n*2-1;
    for(int i=3;i<=n;i+=2)v[0][i] = n*2-i;
    for(int i=2;i<=n;i+=2)v[0][i] = i-1;
    for(int i=1;i<=n;i+=2)v[1][i] = i+1;
    for(int i=n-2;i>0;i-=2)v[1][i] = n*2-i;
    
    for(int i=0;i<2;i++)
        for(int j=1;j<=n;j++)   
            cout << v[i][j] << " \n"[j==n];
}

int main(){
    IOS;
    int t;cin>>t;while(t--)solve();
    return 0;
}
