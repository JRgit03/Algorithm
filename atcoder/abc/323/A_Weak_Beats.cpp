#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve(){
    string s; cin>>s;
    s = "?" + s;
    int f = 1;
    for(int i=2;i<=16;i+=2) 
        f &= (s[i] == '0');
    cout << (f ? "Yes" : "No") << "\n";    
} 

int main(){
    IOS; solve();
    return 0;
}
