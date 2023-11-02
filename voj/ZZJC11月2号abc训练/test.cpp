#include <bits/stdc++.h>
using namespace std;
const int N = 11;
int d1[N],d2[N];
map<int,int> mp1,mp2;
int main(){
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        d1[u]++,d1[v]++;
    }
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        d2[u]++,d2[v]++;
    }
    for(int i=1;i<=8;i++) mp1[d1[i]]++;
    for(int i=1;i<=8;i++) mp2[d2[i]]++;
    cout << (mp1 == mp2 ? "Yes" : "No") << "\n";
    return 0;
}
