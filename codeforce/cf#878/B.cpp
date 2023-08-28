#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void solve(){
	int n,k;cin>>n>>k;
    if(k<=30 && (1<<k) <= n) cout << (1<<k) << "\n";
    else cout << n+1 << "\n";
}

int main(){
	IOS;
	int t;cin>>t;
	while(t--)solve();
	return 0;
}