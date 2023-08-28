#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> vec(n+1);
    for(int i=1;i<=n;i++) cin>>vec[i];

    int cur = 0;
    for(int i=1;i<=n;i++) cur ^= vec[i];
    
    if(n&1){
        cout << cur << "\n";
    }else{
        if(cur!=0){
            cout << -1 << "\n";
        }else{
            cout << 0 << "\n";
        }
    }

}

int main(){
	IOS;
	int t;cin>>t;
	while(t--)solve();
	return 0;
}