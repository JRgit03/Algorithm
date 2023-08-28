#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,t;cin>>n>>t;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    int res = -1 , maxv = -1;
    for(int i=1;i<=n;i++){
        if(a[i] + (i-1) <= t && b[i] > maxv){
            res = i , maxv = b[i];
        }
    }
    cout << res << "\n";
}

int main(){
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
