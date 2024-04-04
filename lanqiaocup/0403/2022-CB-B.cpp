#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

set<int> st = {1,3,5,7,8,10,12};

int check(int a,int b,int c){
	string s = to_string(a);
	if(b < 10) s += "0" + to_string(b);
	else s += to_string(b); 
	if(c < 10) s += "0" +  to_string(c);
	else s += to_string(c);
	int suc = 0;
	for(int i=2;i<s.length();i++)
		suc |= (s[i] - s[i-1] == 1 && s[i-1] - s[i-2] == 1);
//	if(suc) cout << s << "\n";
	return suc;
}

void solve(){
	int y = 2022, m = 1, d = 0;
	int ans = 0;
	while(1){
		d += 1;
		int dd = (m == 2 ? 28 : 30 + st.count(m));
		if(d == dd + 1){
			d = 1;
			m += 1;
			if(m == 13){
				m = 1;
				y += 1;
				break;
			}
		}
		ans += check(y,m,d);
	}
	cout << ans << "\n"; // 14
}

signed main(){
	IOS;
	solve();
	return 0;
} 
