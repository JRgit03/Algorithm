#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void solve(){
    int n,m,d; cin>>n>>m>>d;
    vector<int> a(n+1); for(int i=1;i<=n;i++) cin>>a[i];
    multiset<int> st;
    int ans = 0 , sum = 0;
    for(int i=1;i<=n;i++){
        if(a[i] <= 0) continue;
        if(st.size() < m){
            st.insert(a[i]);
            sum += a[i];
        }else if(*st.begin() < a[i]){
            sum -= *st.begin();
            st.erase(st.begin());
            st.insert(a[i]);
            sum += a[i];
        }
        ans = max(ans , sum - i * d);
    }
    cout << ans << "\n";
}

signed main(){
	IOS;
	int t;cin>>t;
    while(t--)solve();
	return 0;
}