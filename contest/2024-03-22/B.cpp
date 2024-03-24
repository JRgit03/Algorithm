#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n; cin>>n; 
    vector<int> vec(n); for(auto &x : vec) cin>>x;
    vector<int> v; for(int i=1;i<n;i++) v.push_back(vec[i] - vec[i-1]);
    int suc = 1;
    for(int i=1;i<v.size();i++) suc &= (v[i] == v[0]);
    cout << (suc ? "Arithmetic Sequence" : "No") << "\n";
}

signed main(){  
    solve();
    return 0;
}
