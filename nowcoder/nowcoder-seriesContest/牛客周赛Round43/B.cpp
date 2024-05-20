#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e6 + 10;

void solve(){
    int x; cin>>x;
    vector<int> v1,v2;
    for(int i=0;i<=1e7;i++) 
        if(i & 1) v1.push_back(i * i);
        else v2.push_back(i * i);

    int ans = LONG_LONG_MAX;
    int l = 0, r = v1.size() - 1;
    while(l < r){
        int mid = (l + r) >> 1;
        if((x & 1 ? v1[mid] >= x : v2[mid] >= x)) r = mid;
        else l = mid + 1; 
    }
    ans = min(ans, ((x & 1 ? v1[r] : v2[r]) - x));

    l = 0, r = v2.size() - 1;
    while(l < r){
        int mid = (l + r + 1) >> 1;
        if((x & 1 ? v1[mid] <= x : v2[mid] <= x)) l = mid;
        else r = mid - 1; 
    }
    ans = min(ans, x - (x & 1 ? v1[r] : v2[r]));
    ans /= 2;

    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
