#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;cin>>n;
    vector<int> vec(n);
    for(auto &x : vec) cin>>x;
    int ans = 2e9;
    for(int i=1;i<n;i++){
        if(vec[i] < vec[i-1]) {
            ans = 0 ; break;
        }
        ans = min(ans,(vec[i]-vec[i-1]+2)/2);
    }
    cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;cin>>t;while(t--)solve();
	return 0;
}