// 蓝桥杯2022年第十三届省赛真题-刷题统计
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

void solve(){
	int a,b,n; cin>>a>>b>>n;
	__int128 x = a, y = b, z = n;
	__int128 ans = n / (5 * a + 2 * b) * 7;
	n -= n / (5 * a + 2 * b) * (5 * a + 2 * b) ;
	for(int i=1;i<=7;i++){
		if(n <= 0) break;
		ans += 1;
		if(i <= 5) n -= a;
		else n -= b;
	}
	cout << (long long)(ans) << "\n"; 
}

signed main(){
	IOS;
	solve();
	return 0;
} 

// 10 20 99

// 8
