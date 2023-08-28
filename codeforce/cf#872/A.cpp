#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

bool check(string &str){
    int  n =(int)(str.length());str = "?" + str; 
    for(int i=1;i<=n/2;i++){
        if(str[i] != str[n-i+1]) 
            return true;
    }
    return false;
}

void solve(){
    string s;cin>>s;
    int n = s.length() , res = -1; 
    s = "?" + s;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            string str = s.substr(i,j-i+1);
            if(check(str)) res = max(res,j-i+1);
        }
    cout << res << "\n";return;    
}

int main(){IOS;int t;cin>>t;while(t--)solve();return 0;}