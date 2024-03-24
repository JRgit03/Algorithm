#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;
const int N = 3e5 + 10;
int n;
string s; 

void solve(){
    cin>>n;
    cin>>s; s = "?" + s;
    int l0 = 0, r1 = 0;
    vector<pair<int,double>> ans;
    for(int i=1;i<=n;i++){
        if(s[i] == '1') r1 += 1; 
    }    
    for(int i=0;i<=n;i++){
        if(s[i] == '0') l0 += 1;
        else if(s[i] == '1') r1 -= 1;
        if((i + 2 - 1) / 2 <= l0 && (n - i + 2 - 1) / 2 <= r1){
            ans.push_back({i, abs(n * 1.0 / 2 - i)});
        }
    }
    sort(ans.begin(), ans.end(), [&](auto &p, auto &q){
        return p.second == q.second? p.first < q.first : p.second < q.second; 
    });
    cout << ans[0].first << "\n";
}

signed main(){
    IOS;
    int t; cin>>t;
    while(t--) 
        solve();
    return 0;
}
