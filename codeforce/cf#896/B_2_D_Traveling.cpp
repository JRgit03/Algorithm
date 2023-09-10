#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int x[N],y[N];

void solve(){
    int n,k,a,b; cin>>n>>k>>a>>b;
    int sx,sy,ex,ey;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
        if(i == a) sx = x[i] , sy = y[i];
        if(i == b) ex = x[i] , ey = y[i];
    }
    int ans1 = 1e16 , ans2 = 1e16;
    for(int i=1;i<=k;i++){
        int xx = x[i] , yy = y[i];
        ans1 = min(ans1,abs(sx-xx)+abs(sy-yy));
        ans2 = min(ans2,abs(ex-xx)+abs(ey-yy));
    }
    cout << min(ans1+ans2 , abs(sx-ex)+abs(sy-ey)) << "\n";
}

signed main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
