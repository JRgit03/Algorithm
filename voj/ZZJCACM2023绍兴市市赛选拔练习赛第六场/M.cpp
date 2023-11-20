#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 10;
int a[maxn];

void solve(){
    int n,b; cin>>n>>b;
    bool f = false;
    for(int i=0;i<n;i++) {
        int x; cin>>x;
        f |= ((x + b) % 7 == 0);
    }
    cout << (f ? "Yes" : "No") << "\n";
}

int main(){
    int t; cin>>t;
    while(t--) 
        solve();
    return 0;
}
