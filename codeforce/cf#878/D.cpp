#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void solve(){
	int n;cin>>n;
    vector<int> a(n); for(auto &x : a) cin>>x; sort(a.begin(),a.end());
  
    auto check = [&](int k){ //判断 等待时间k秒是否能满足
        int cur = 1 , mins = -1 , maxs = -1;
        for(int i=0;i<n;i++){
            if(i==0 || mins == -1){
                mins = a[i] , maxs = a[i];
            }else{
                maxs = a[i]; int mid = mins + maxs >> 1;
                if(max(maxs-mid,mid-mins)>k){
                    mins = -1; cur++; i--;
                }
            }
            if(cur > 3) return false; 
        }
        return true;
    };

    int l = 0 , r = a[n-1];
    while(l<r){
        int mid = l + r >> 1; 
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << "\n";
}

signed main(){
	IOS;
	int t;cin>>t;
	while(t--)solve();
	return 0;
}