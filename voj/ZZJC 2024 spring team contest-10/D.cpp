#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n,k;
int t[N];
int b[N];

void add(int l,int r){
    b[l] += 1, b[r+1] -= 1;
}

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>t[i];
        add(t[i], min(100000, t[i] + 1000 - 1));
    }
    int sz = 0;
    for(int i=1;i<=100000;i++) {
        b[i] += b[i-1];
        sz = max(sz, b[i]);
    }
    int ans = (sz + k - 1) / k;
    cout << ans << "\n";
}

signed main(){
    solve();
    return 0;
}
