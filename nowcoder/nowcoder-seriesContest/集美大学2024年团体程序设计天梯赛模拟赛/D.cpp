#include <bits/stdc++.h>
#define int long long
using namespace std;

set<char> st = {',', '.', '!', '?', ' '};

void solve(){
    string s; getline(cin, s);
    vector<int> ans;
    int n = s.length();
    for(int i=0;i<n;i++){
        if(st.count(s[i])) continue;
        int j=i;
        while(j<n && !st.count(s[j])) j += 1;
        ans.push_back((j - i) % 10);
        i = j - 1;
    }
    for(auto &x : ans) cout << x;
}

signed main(){
    solve();
    return 0;
}
