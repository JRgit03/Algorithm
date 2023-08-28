#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> a(n); for(auto &x : a) cin>>x;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(i>0 && a[i] < a[i-1]) ans.push_back(a[i]);
        ans.push_back(a[i]);
    }
    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++) cout << ans[i] << " \n"[i==ans.size()-1];
}

int main(){
	IOS;
	int t;cin>>t;
    while(t--)solve();
	return 0;
}