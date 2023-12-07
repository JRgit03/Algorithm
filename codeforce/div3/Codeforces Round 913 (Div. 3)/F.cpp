#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> a(2*n+1); 
    for(int i=1;i<=n;i++) {
        int x; cin>>x;
        a[i] = a[n+i] = x;
    }
    int ans = INT_MAX;
    for(int i=1;i<=n;i++){
        int j=i+1;
        while(j<=2*n && a[j] >= a[j-1]) j += 1;
        int sz = j - i;
        if(sz >= n){
            int l = n - i + 1, r = n - l;
            ans = min({ans,l,r+2});
            if(l == n) ans = 0;
        }
        i = j - 1;
    }
    for(int i=1;i<=n;i++){
        int j=i+1;
        while(j<=2*n && a[j] <= a[j-1]) j += 1;
        int sz = j - i;
        if(sz >= n){
            int l = n - i + 1, r = n - l;
            ans = min({ans,l+1,r+1});
        }
        i = j - 1;
    }
    if(ans == INT_MAX) ans = -1;
    cout << ans << "\n";
}

int main(){
    int t; cin>>t;
    while(t--)
        solve();
    return 0;
}
