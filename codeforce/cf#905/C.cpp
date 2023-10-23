#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve(){
    int n,k; cin>>n>>k;
    vector<int> a(n); for(auto &x : a) cin>>x , x %= k;
    int ans = INT_MAX;
    sort(a.begin(),a.end());
    if(a[0] == 0) {
        cout << 0 << "\n"; 
        return;
    }
    if(k!=4)cout << k - a[n-1] << "\n";
    else {
        int ans = INT_MAX;
        for(int i=1;i<n;i++){
            if(a[i] > 2)break;
            ans = min(ans,abs(a[i]-2)+abs(a[i-1]-2));
        }
        ans = min(ans,k-a[n-1]);
        cout << ans << "\n";
    }
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
