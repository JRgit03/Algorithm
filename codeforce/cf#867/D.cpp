#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    if(n==1) {cout << 1 << "\n"; return;}
    if(n&1) {cout << -1 << "\n";return;}
    vector<int> tar(n+1) , res(n+1);
    for(int i=1,x=0;i<=n;i+=2,x++) tar[i] = x;
    for(int i=2,x=n-1;i<=n;i+=2,x--) tar[i] = x;

    //for(int i=1;i<=n;i++) cout << tar[i] << " \n"[i==n];
    
    for(int i=1;i<=n;i++) {
        res[i] = tar[i] - tar[i-1];
        if(res[i] <= 0 ) res[i] += n;
    }

    for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
}

int main(){
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
