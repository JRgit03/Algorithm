#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n; cin>>n;
    vector<array<int,2>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i][0]; a[i][1] = i;
    } 
    int x,y; cin>>x>>y;
    int c = (a[x-1][0] + a[y-1][0] + 2 - 1) / 2;
    vector<array<int, 2>> b(n);
    for(int i=0;i<n;i++) b[i] = {abs(c - a[i][0]), a[i][1]};
    sort(b.begin(), b.end());
    cout << b[0][1] + 1 << "\n";
}

signed main(){
    solve();
    return 0;
}
