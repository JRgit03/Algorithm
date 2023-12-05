#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> a(n); 
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    set<int> st = {a.begin(),a.end()};
    if(n == 1){
        cout << 1 << "\n";
        return;
    }
    vector<int> b; n = a.size();
    for(int i=1;i<n;i++) b.push_back(a[i]-a[i-1]); //for(auto x : b) cout << x << " "; cout << "\n";
    int x = b[0]; for(int i=1;i<b.size();i++) {
		x = __gcd(x,b[i]);
	}
    int s = 0,ans = 0; 
    for(int i=(int)b.size()-1;i>=0;i--){
        s += b[i] / x;
        ans += s;
    }
    int cnt = 1;
    while(st.count(a.back()-x*cnt)) cnt += 1;
    cout << ans + cnt << "\n";
}

signed main(){
    IOS;
    int T; cin>>T;
    while(T--)
        solve();
    return 0;
}
//1
//5
//1 -19 17 -3 -15