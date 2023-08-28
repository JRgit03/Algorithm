#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void solve(){
	int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]==i || (a[i]>=1 && a[i]<=i-1)){
            cout << "YES" << "\n";return;
        }
    }
    cout << "NO" << "\n";return;
}

int main(){
	IOS;
	int t;cin>>t;
	while(t--)solve();
	return 0;
}