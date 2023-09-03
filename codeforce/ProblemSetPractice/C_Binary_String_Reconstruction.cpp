#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve(){
    string s; cin>>s;
    int x; cin>>x;
    int n = s.length();
    string w = string(n,'1');
    for(int i=0;i<n;i++){
        if(s[i] == '0'){
            if(i-x >= 0) w[i-x] = '0';
            if(i+x < n)  w[i+x] = '0';
        }
    }
    for(int i=0;i<n;i++){
        if(s[i] == '1'){
            if((i-x >= 0 && w[i-x] == '1') || (i+x < n  && w[i+x] == '1')) continue;
            else {
                cout << -1 << "\n";
                return;
            }
        }
    }
    cout << w << "\n";
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
