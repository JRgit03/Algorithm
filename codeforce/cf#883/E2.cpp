#include <bits/stdc++.h>
#define int long long 
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

const int N = 1e6 , INF = 1e18;
unordered_set<int> st;

void init(){
    for(__int128 i=2;i<=N;i++){
        __int128 sum = 1 + i + i * i , add = i * i * i;
        while(sum <= INF){
            sum += add; 
            st.insert(sum);
            add *= i;
        }
    }
}

void solve(){
	int n;cin>>n;
    auto check = [&](int n){
        int k = 4 * n - 3;
        int kk = sqrt(k);
        return (kk * kk == k) && (kk-1)/2 >= 2 && ((kk - 1) & 1) == 0;
    }; 
    cout << (check(n) || st.count(n) ? "YES" : "NO") << "\n";
}

signed main(){
	IOS;
    init();
	int t;cin>>t;
    while(t--)solve();
	return 0;
}