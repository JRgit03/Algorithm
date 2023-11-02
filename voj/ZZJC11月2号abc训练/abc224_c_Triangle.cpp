 /**
 * 模拟 三角形判定
 * https://atcoder.jp/contests/abc224/tasks/abc224_c
 * 
 * 题意：给你n个点,无重点,求构成合法三角形的个数
 */
#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;

signed main(){
	int n; cin>>n;
	vector<pair<int,int>> p(n);
	for(int i=0;i<n;i++){
		int a,b; cin>>a>>b;
		p[i] = {a,b};
	}
	int ans = 0;
	auto check = [&](int i,int j,int k){ // i j k 三点 判断 是否共线
		return (p[k].y - p[j].y) * (p[j].x - p[i].x) != (p[j].y - p[i].y) * (p[k].x - p[j].x);	
	};
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)	
			for(int k=j+1;k<n;k++)
				ans += check(i,j,k);
	cout << ans << "\n";
	return 0;
}
// A3,3

// signed main(){
// 	int n; cin>>n;
// 	vector<pair<int,int>> p(n);
// 	for(int i=0;i<n;i++){
// 		int a,b; cin>>a>>b;
// 		p[i] = {a,b};
// 	}
// 	int ans = n * (n - 1) * (n - 2) / 6;
// 	auto check = [&](int i,int j,int k){
// 		return (p[k].y - p[j].y) * (p[j].x - p[i].x) == (p[j].y - p[i].y) * (p[k].x - p[j].x);	
// 	};
// 	for(int i=0;i<n;i++)
// 		for(int j=i+1;j<n;j++)	
// 			for(int k=j+1;k<n;k++)
// 				ans -= check(i,j,k);
// 	cout << ans << "\n";
// 	return 0;
// }