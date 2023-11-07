#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n; cin>>n;
    vector<int> vec(n); for(auto &x : vec) cin>>x;
    int ans = 0;
    for(int i=1;i<n;i++) {
        if(vec[i] < vec[i-1]) {
            ans += vec[i-1] - vec[i];
            vec[i] = vec[i-1];
        }
    }
    cout << ans << "\n";
    return 0;
}
