#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void solve(){
	int n;cin>>n;
    int ans=0;
    while(n--){int x,y;cin>>x>>y;ans+=(x-y>0);}
    cout << ans << "\n";
}

int main(){
	IOS;
	int t;cin>>t;
    while(t--)solve();
	return 0;
}