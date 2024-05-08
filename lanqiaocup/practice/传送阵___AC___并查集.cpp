// https://www.dotcpp.com/oj/problem3244.html
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e6 + 10;
int n;
int sz[N];
int p[N];

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void merge(int a,int b){
    int pa = find(a), pb = find(b);
    if(pa != pb){
        p[pa] = pb;
        sz[pb] += sz[pa];
    }
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) {
        p[i] = i, sz[i] = 1;
    }
    for(int i=1;i<=n;i++){
        int u = i, v; cin>>v;
        merge(u, v);
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans, sz[find(i)]);
        if(i - 1 >= 1 && find(i) != find(i-1)) ans = max(ans, sz[find(i)] + sz[find(i-1)]);
        if(i + 1 <= n && find(i) != find(i+1)) ans = max(ans, sz[find(i)] + sz[find(i+1)]); 
    } 
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
