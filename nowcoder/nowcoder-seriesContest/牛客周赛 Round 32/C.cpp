#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n; cin>>n;
    vector<int> vec(n); for(auto &x : vec) cin>>x;
    sort(vec.begin(), vec.end());
    int ans = 0;
    for(int i=0;i<n;i++) ans += abs(vec[i] - (i + 1));
    cout << ans << "\n";
    return 0;
}
