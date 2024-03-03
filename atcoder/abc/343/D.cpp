#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n,m; cin>>n>>m;
    vector<int> a(m+1),b(m+1);
    vector<int> c(n+1);
    for(int i=1;i<=m;i++) cin>>a[i]>>b[i];
    map<int,int> mp; mp[0] = n; 
    for(int i=1;i<=m;i++){
        mp[c[a[i]]] -= 1;
        if(mp[c[a[i]]] == 0) mp.erase(c[a[i]]); 
        c[a[i]] += b[i];
        mp[c[a[i]]] += 1;
        cout << mp.size() << "\n";
    }
    return 0;
}
