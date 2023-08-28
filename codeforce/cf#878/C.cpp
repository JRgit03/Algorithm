#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void solve(){
	int n,k,q,res=0;cin>>n>>k>>q;
    vector<int> f(n);
    for(auto &x : f) {cin>>x;x=x<=q;}
    for(int i=0;i<n;i++){
        if(!f[i])continue;
        int sum = 0 , j = i;
        while(j<n && f[j]) j++,sum++; i=j;
        if(sum>=k)res += (sum+1)*(sum-k+1) - (k+sum)*(sum-k+1)/2;
    }
    cout << res << "\n";
}

signed main(){
	IOS;
	int t;cin>>t;
	while(t--)solve();
	return 0;
}