#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

void solve(){	
	string s = "2022";
	int ans = 0;
	for(auto &c : s) ans = ans * 9 + c - '0';
	cout << ans << "\n"; // 1478
}

signed main(){
	IOS;
	solve();
	return 0;
} 
