#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 55;
int f[N];

bool dfs(int n,int x,int y){
    if(!n) return true;
    
    if(y > f[n]) return dfs(n-1,y-f[n],x);
    else if(y <= f[n-1]) return dfs(n-1,y,x);
    else return false;
    
}


void solve(){
    int n,x,y;cin>>n>>x>>y;
    cout << (dfs(n,x,y) ?  "YES" : "NO" ) << "\n";
}

signed main(){
    f[0] = 1;f[1] = 1;
    for(int i=2;i<=44;i++) f[i] = f[i-1] + f[i-2];
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
