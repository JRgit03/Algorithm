#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void solve(){
    int n;string s;cin>>n>>s;
    char c;int idx;
    for(int i=0;i<n;i++){
        char ch = s[i];
        if(i==0){
            c = ch , idx = 0;
        }else{
            if(ch <= c){
                c = ch , idx = i;
            }
        }
    }
    cout << s[idx] << s.substr(0,idx) << s.substr(idx+1) << "\n";
}

int main(){
	IOS;
	int t;cin>>t;
	while(t--)solve();
	return 0;
}