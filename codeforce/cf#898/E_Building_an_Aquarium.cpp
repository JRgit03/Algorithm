#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 2e5 + 10;
int n,maxw;
int a[N];

void solve(){
    cin>>n>>maxw;
    for(int i=1;i<=n;i++) cin>>a[i];

    auto check = [&](int h){
        int curw = 0;
        for(int i=1;i<=n;i++)   
            if(h - a[i] > 0)
                curw += h - a[i];
        return curw <= maxw;
    };

    int l = 0 , r = 2e9;
    while(l < r){ 
        int mid = l + r + 1 >> 1;
        // cout << l << " " << r << " " << mid << " " << check(mid) << "\n";
        if(check(mid)) l = mid; 
        else r = mid - 1;
    }    
    cout << r << "\n";
}

signed main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
