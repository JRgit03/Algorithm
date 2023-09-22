#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve(){
    int cnt = 0;
    string s = "abc", t; cin>>t;
    for(int i=0;i<3;i++)
        cnt += (s[i] != t[i]);
    cout << (cnt == 3 ? "NO" : "YES") << "\n";
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
