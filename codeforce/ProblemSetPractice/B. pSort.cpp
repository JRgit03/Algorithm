#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
int n;
int a[N];
int p[N];

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void merge(int u,int v){
    if(u > v) swap(u,v);
    int pa = find(u), pb = find(v);
    if(pa != pb) p[pb] = pa;    
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) p[i] = i;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) {
        int d; cin>>d;
        if(i-d >= 1) merge(i,i-d);
        if(i+d <= n) merge(i,i+d);
    }
    int suc = 1;
    for(int i=1;i<=n;i++)
        if(find(i) != find(a[i])) suc = false;
    cout << (suc ? "YES" : "NO") << "\n";
    return 0;
}
