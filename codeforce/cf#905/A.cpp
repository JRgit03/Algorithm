#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
typedef long long ll;

vector<int> pos(11);

void solve(){
    string s; cin>>s; 
    int pre = 1 , ans = 4;
    for(auto c : s) ans += abs(pos[c-'0'] - pos[pre]) , pre = pos[c-'0'];
    cout << ans << "\n";
}

signed main(){
    IOS;
    for(int i=1;i<=10;i++) pos[i] = i; pos[0] = 10;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
