#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int l[maxn],r[maxn];

void solve(){
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    l[1] = 1; for(int i=2;i<=n;i++) l[i] = (a[i] > a[i-1] ? l[i-1] + 1 : 1);
    r[n] = 1; for(int i=n-1;i>=1;i--) r[i] = (a[i] > a[i+1] ? r[i+1] + 1 : 1);
    bool f = false;
    for(int i=2;i<=n-1;i++){
        //cout << l[i] + r[i] << "\n";
        if(l[i] + r[i] == n + 1)
            f = true;
    }
        
    cout << (f ? "Yes" : "No") << "\n"; 
}

int main(){
    int t; cin>>t;
    while(t--) 
        solve();
    return 0;
}
