#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int tar = a[1] != n ? n : n-1;
    int r = 1; while(a[r] != tar) r++;
    
    if(r==n){
        
    }

    r--;

    int tail = a[r];
    int l = r;
    while(l-1 >= 1 && a[l-1] < tail) l--;

    cout << l << " " << r << "\n";

    for(int i=r+1;i<=n;i++) cout << a[i] << " ";
    for(int i=r;i>=l;i--) cout << a[i] << " ";
    for(int i=1;i<=l-1;i++) cout << a[i] << " ";
    cout << "\n";
}

int main(){
    int t;cin>>t;while(t--)solve();return 0;
}
