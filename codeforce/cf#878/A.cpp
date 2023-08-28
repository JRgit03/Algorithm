#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void solve(){
	int n;cin>>n;string s;cin>>s;
    string res = "";
    for(int i=0;i<n;i++){
        int j=i+1;
        while(j<n && s[j] != s[i]) j++;
        res += s[i]; i = j;
    }
    cout << res << "\n";
}

int main(){
	IOS;
	int t;cin>>t;
	while(t--)solve();
	return 0;
}