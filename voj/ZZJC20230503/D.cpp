#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,q;cin>>n>>q;
    vector<int> v(n+1),v0(n+1),v1(n+1);
    for(int i=1;i<=n;i++){
        int x;cin>>x; 
        if(x&1) x=1;
        else x=0;
        if(x) v1[i] = 1;
        else v0[i] = 1;
    }
    for(int i=1;i<=n;i++) v0[i] += v0[i-1] , v1[i] += v1[i-1];
    int cur = v1[n];
    while(q--){
        int l,r,k;cin>>l>>r>>k;
        if(k&1) cur += v0[r] - v0[l-1];
        else cur -= v1[r] - v1[l-1];
        cout << (cur & 1 ? "YES" : "NO") << "\n";
        if(k&1) cur -= v0[r] - v0[l-1];
        else cur += v1[r] - v1[l-1];
    }
}

int main(){
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
