#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n,k; cin>>n>>k;
    vector<int> a(n); for(auto &x : a) cin>>x;
    sort(a.begin(), a.end());
    double ans = 0;
    for(int i=0;i<n;i++){
        int L = i, R = a[i] + k;
        int l = i, r = n - 1;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(a[mid] <= R) l = mid;
            else r = mid - 1;
        }
        ans = max(ans, (r - i + 1) * 1.0 / n);
    }
    printf("%.10lf\n", ans); 
}

signed main(){
    solve();
    return 0;
}
