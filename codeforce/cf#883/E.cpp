#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

const int N = 1e6;
unordered_set<int> st;

void init(){
    for(int i=2;i<=N;i++){
        int sum = 1 + i + i * i , add = i * i * i;
        while(sum <= N){
            st.insert(sum);
            sum += add ; add *= i;
        }
    }
}

void solve(){
	int n;cin>>n;
    cout << (st.count(n) ? "YES" : "NO") << "\n";
}

signed main(){
	IOS;
    init();
	int t;cin>>t;
    while(t--)solve();
	return 0;
}