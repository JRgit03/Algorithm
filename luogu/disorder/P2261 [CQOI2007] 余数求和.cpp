#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;

signed main(){
    IOS;
    int n,k; cin>>n>>k;
    int ans = n*k;
    int L=1,R;
    for(;L<=k&&L<=n;L=R+1){
        if(k / L == 0) break;
        R = min(k/(k/L),n);
        ans -= k/L * (L+R) * (R-L+1) / 2;
    }
    cout << ans << "\n";
    return 0;
}
