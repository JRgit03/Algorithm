#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e6 + 10;
int n,m;
int p[N];

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void merge(int a,int b){
    int pa = find(a), pb = find(b);
    if(pa != pb){
        p[pa] = pb;
    }
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) p[i] = i;
    while(m--){
        char op; int a,b; cin>>op>>a>>b;
        if(op == 'M') merge(a, b);
        else cout << (find(a) == find(b) ? "Yes" : "No") << "\n";
    }
}

signed main(){
    IOS;
    solve();
    return 0;
}
