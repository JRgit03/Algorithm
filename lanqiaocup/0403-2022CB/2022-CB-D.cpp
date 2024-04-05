#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){ return (a > b ? a : b);}
int min(int a,int b){ return (a < b ? a : b);}

void solve(){
	int n; cin>>n;
	for(int i=1;i<=n;i++){
		int lmax = (i - 1) * 2, rmax = (n - i) * 2;
		cout << max(lmax, rmax) << "\n";
	}
}

signed main(){
	IOS;
	solve();
	return 0;
} 
