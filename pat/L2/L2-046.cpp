#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
int n,c;
int ans,t;
string s[N];
int a[N];

void solve(){
	cin>>n>>c;
	priority_queue<int> heap;
	for(int i=1;i<=n;i++) {
		cin>>s[i]>>a[i];
		heap.push(a[i]);
	}
	set<pair<int,int>> st;
	while(heap.size()){
		int x = heap.top(); heap.pop();
		if(x >= c){
			ans += 1;
			if(x - c > 0) heap.push(x - c);
		}else if(x > 0){
			auto it = st.lower_bound({x, -1});
			if(it == st.end()){
				ans += 1;
				st.insert({c - x, ++t});
			}else{
				int y = -1, id = -1;
				for(auto [a,b] : st){
					if(a >= x){
						if(id == -1 || b < id) y = a, id = b;
					}
				}
				st.erase(st.lower_bound({x,id}));
				if(y - x > 0) st.insert({y-x,id});
			}
		}
	}
	for(int i=1;i<=n;i++) cout << s[i] << " " << (a[i] + c - 1) / c << "\n";
	cout << ans << "\n";
}

int main(){
	solve();
	return 0;
}