#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;string s;cin>>n>>s;
    vector<int> allcnt(26) , cnt(26);
    for(auto c : s) allcnt[c-'a']++;
    
    int maxx = *max_element(allcnt.begin(),allcnt.end());

    if(n&1 || maxx > n/2) {cout << -1 << "\n"; return; }

    int same = 0; s = "?" + s;
    for(int i=1;i<=n/2;i++)
        if(s[i] == s[n-i+1])
            cnt[s[i]-'a']++ , same++;
    
    maxx = *max_element(cnt.begin(),cnt.end());

    if(maxx > same/2) cout << maxx << "\n";
    else cout << (same+2-1) / 2 << "\n";
}

int main(){
    int t;cin>>t;while(t--)solve();
    return 0;
}
