#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){ return (a > b ? a : b);}
int min(int a,int b){ return (a < b ? a : b);}

const int N = 1e5 + 10, mod = 1e9 + 7;
int ma,mb;
int a[N],b[N],d[N];

void solve(){
 	int n; cin>>n; // ¸ßÎ»->µÍÎ» 
 	cin>>ma; for(int i=ma;i>=1;i--) cin>>a[i];
 	cin>>mb; for(int i=mb;i>=1;i--) cin>>b[i];
	for(int i=1;i<=ma;i++) d[i] = max(2, max(a[i] + 1, b[i] + 1));
	int res1 = 0, res2 = 0;
	for(int i=ma;i>=1;i--) {
		res1 = res1 * d[i] + a[i];
		res1 %= mod;
	}
	for(int i=mb;i>=1;i--) {
		res2 = res2 * d[i] + b[i];
		res2 %= mod;
	}
	int ans = ((res1 - res2) % mod + mod) % mod;
	cout << ans << "\n"; 
}

signed main(){
	IOS;
	solve();
	return 0;
} 

/*
11
3
10 4 0
3
1 2 0
*/
