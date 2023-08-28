#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define debug(x) cout << x << "\n";
using namespace std;

void solve(){
	string s; cin>>s;
    int n = s.length() * 2;
    string ans1 = "" , ans2 = "";
    for(int i=1;i<=n;i++) ans1 += i & 1 ? '(' : ')' , ans2 += i <= n/2 ? '(' : ')';
    bool f1 = true;
    for(int i=0;i<n/2;i++) 
        if(ans1.substr(i,n/2) == s)
            f1 = false;
    if(f1) {
        cout << "YES" << "\n";
        cout << ans1 << "\n";
        return;
    }
    bool f2 = true;
    for(int i=0;i<n/2;i++){
        if(ans2.substr(i,n/2) == s){
            f2 = false;
        }
    }
        
    if(f2) {
        cout << "YES" << "\n";
        cout << ans2 << "\n";
        return;
    }
    cout << "NO" << "\n";
}

int main(){
	IOS;
	int t;cin>>t;while(t--)solve();
	return 0;
}