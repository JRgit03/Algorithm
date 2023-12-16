#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> vec(n); for(auto &x : vec) cin>>x;
    sort(vec.begin(),vec.end());
    int ans = 0;
    for(int i=0;i<n;i++) ans += abs(vec[n/2] - vec[i]);
    cout << ans << "\n";
    return 0;
}
