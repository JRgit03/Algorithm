#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b) {return (a > b ? a : b);}
int min(int a,int b) {return (b > a ? a : b);}

const int N = 1e5 + 10;
int n;
int a[N];
int col[N];
vector<int> g[N];

void dfs(int u,int f){
    for(auto &v : g[u]){
        if(v == f) continue;
        if(a[v] > a[u])  
    }
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) a[i];
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v); g[v].push_back(u);
    }
    dfs(1,1);
}

signed main(){
    IOS; solve();
    return 0;
}
