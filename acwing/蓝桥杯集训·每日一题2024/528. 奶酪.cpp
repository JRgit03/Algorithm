#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 10;
int n,h,r;
int p[N];
int w[N];

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x]; 
}

void merge(int a,int b){
    int pa = find(a), pb = find(b);
    if(pa != pb){
        p[pa] = pb;
        w[pb] += w[pa];
    }
}

int x[N],y[N],z[N];

void solve(){
    cin>>n>>h>>r;
    for(int i=1;i<=n;i++) p[i] = i, w[i] = 0;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i]>>z[i];
        if(h - z[i] <= r) w[i] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int dist = (x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]) +  (z[j] - z[i]) * (z[j] - z[i]);
            if(dist <= 4 * r * r) merge(i,j);
        }
    }
    int suc = 0;
    for(int i=1;i<=n;i++)
        if(z[i] - 0 <= r && w[find(i)] > 0)
            suc = 1;
    cout << (suc ? "Yes" : "No") << "\n";
}

signed main(){
    int t; cin>>t;
    while(t--) solve();
    return 0;
}