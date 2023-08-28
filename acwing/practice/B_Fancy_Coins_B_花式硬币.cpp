#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void solve(){   
    int m,k,a,b;cin>>m>>k>>a>>b;
    int r = m % k;
    int s = m / k;
    if(a>=r){
        a -= r;
        b += a / k;
        cout << max(0,s-b) << "\n";
    }else{
        cout << max(0,s-b) + r - a << "\n";
    }
}

int main(){
	IOS;
	int t;cin>>t;while(t--)solve();
	return 0;
}