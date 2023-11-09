#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> ans(n,1);
    map<int,int> mp;
    map<int,vector<int>> pos;
    vector<int> a(n); for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]] += 1;
        pos[a[i]].push_back(i);
    }
    vector<int> op;
    for(auto [val,sz] : mp){
        if(sz >= 3){
            vector<int> vec;
            for(auto idx : pos[val]) vec.push_back(idx);
            op.push_back(vec[0]);
        }else if(sz == 2){
            vector<int> vec;
            for(auto idx : pos[val]) vec.push_back(idx);
            op.push_back(vec[0]);
        }
    }   
    if(op.size() < 2) {
        cout << -1 << "\n";
        return;
    }
    for(int i=0;i<op.size();i++) ans[op[i]] = (i & 1 ? 2 : 3);
    for(auto x : ans) cout << x << " "; cout << "\n";
}

int main(){
    int t;cin>>t;
    while(t--)
        solve();
    return 0;
}
