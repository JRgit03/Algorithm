#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n;
int ans1,ans2;
int a[N];

int max(int a,int b){
	return a > b ? a : b;
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	stack<int> stk1, stk2;
	for(int i=1;i<=n;i++){
		if(i == 1){
			stk1.push(a[i]);
		}else{
			if(a[i] < stk1.top()){
				stk1.push(a[i]);
			}else{
				if(stk2.size() == 0 || a[i] > stk2.top()){
					stk2.push(a[i]);
				}else{
					ans1 += 1; 
					ans2 = max(ans2, stk1.size());
					while(stk1.size()) stk1.pop();
					while(stk2.size() && stk2.top() > a[i]){
						stk1.push(stk2.top()); stk2.pop();
					}
					stk1.push(a[i]);
				}
			}
		}
	}
	if(stk1.size()) {
		ans1 += 1; ans2 = max(ans2, stk1.size());
	}
	if(stk2.size()) {
		ans1 += 1; ans2 = max(ans2, stk2.size());
	}
	cout << ans1 << " " << ans2 << "\n";
}

int main(){
	solve();
	return 0;
}