#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main(){
    int n; cin>>n;
    vector<int> vec(n); for(auto &x : vec) cin>>x;
    sort(vec.begin(),vec.end());
    long long ans = 1;
    for(int i=0;i<n;i++) ans = ans * max(0,vec[i]-i) % mod;
    cout << ans << "\n";
    return 0;
}
