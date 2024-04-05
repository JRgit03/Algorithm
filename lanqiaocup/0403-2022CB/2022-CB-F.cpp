#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){ return (a > b ? a : b);}
int min(int a,int b){ return (a < b ? a : b);}
const int N = 5e2 + 10;
int n,m,k;
int a[N][N];
int s[N][N];

int ask(int x1,int y1,int x2,int y2){
	return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}

void solve(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
	int ans = 0;
	for(int x1=1;x1<=n;x1++){ // 枚举上边界 
		for(int x2=x1;x2<=n;x2++){ // 枚举下边界 
			for(int r=1,l=1;r<=m;r++){ // 同向双指针维护数组字段和<=k;
				while(l <= r && ask(x1,l,x2,r) > k) l += 1;
				if(l <= r && ask(x1,l,x2,r) <= k) ans += r - l + 1; 
			} 
		}
	}
	cout << ans << "\n";
}

signed main(){
	IOS;
	solve();
	return 0;
} 

/*
3 4 10
1 2 3 4
5 6 7 8
9 10 11 12
*/

