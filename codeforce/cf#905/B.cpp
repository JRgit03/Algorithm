#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
typedef long long ll;

void solve(){
    int n,k; cin>>n>>k;
    string s; cin>>s;
    map<char,int> mp;
    for(auto &c : s) mp[c] += 1;
    int ne = n - k;
    int sz = 0;
    for(auto [_,cnt] : mp) sz += (cnt / 2) * 2;
    if(ne & 1) ne--;
    cout << (sz >= ne ? "YES" : "NO") << "\n";
}

signed main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
