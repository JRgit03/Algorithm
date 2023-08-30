#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve(){
    int n;cin>>n; vector<int> p(n+1); map<int,int> pos;
    for(int i=1;i<=n;i++) cin>>p[i] , pos[p[i]] = i;
    int ans = 0;
    for(int i=2;i<=n;i++)
        if(pos[i] < pos[i-1]) 
            ans++;
    cout << ans << "\n";
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--) solve();
    return 0;
}
