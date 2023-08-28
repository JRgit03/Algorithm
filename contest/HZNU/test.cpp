#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void solve(){
	
}

int main(){
	IOS;
	multiset<int> st;
    for(int i=10;i<=1;i++) st.insert(i);
    st.erase(st.lower_bound(3));
    for(auto x : st) cout << x << "\n";
	return 0;
}