#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n; cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;i++) cin>>s[i];
    auto f = [&](int i,int j){
        string s1 = s[i], s2 = s[j];
        int res = 0;
        for(int l=0;l<s1.length();l++){
            for(int r=l;r<s1.length();r++){
                string sub = s1.substr(l, r-l+1);
                if(s2.find(sub) != -1){
                    res = max(res, r - l + 1);
                }
            }
        }
        return res;
    };
    int ans = 0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            ans = max(ans, f(i,j));
    cout << ans << "\n";
}

signed main(){
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
