#include <bits/stdc++.h>
#define int long long 
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    
    if(n&1){
        cout << "YES" << "\n";return;
    }else{
        for(int i=2;i<n;i++){
            int dif = a[i] - a[i-1];
            a[i] -= dif;
            a[i+1] -= dif;
        }
        cout << (a[n] >= a[n-1] ?  "YES" : "NO" ) << "\n";
    }
}

signed main(){
    IOS;
    int t;cin>>t;
    while(t--)solve(); 
    return 0;
}
