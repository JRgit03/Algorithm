#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void solve(){
    int n; cin>>n;
    int l = 1 , r = INT_MAX , ans = 1e18;
    auto check = [&](int k){
        return k * (k-1) / 2 <= n;
    };
    while(l<r){
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid , ans = min(ans , mid + n - mid * (mid-1) / 2 );
        else r = mid - 1;
    }
    cout << ans << "\n";
}

signed main(){
	IOS;
	int t;cin>>t;while(t--)solve();
	return 0;
}