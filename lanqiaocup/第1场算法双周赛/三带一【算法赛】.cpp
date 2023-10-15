#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve(){
    string s; cin>>s;
    map<int,int> cnt;
    for(auto &c : s) cnt[c] += 1;
    int maxsz = 0;
    for(auto &[_,sz] : cnt) 
        maxsz = max(maxsz, sz);
    cout << (maxsz == 3 ? "Yes" : "No") << "\n";
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
