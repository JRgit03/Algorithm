#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        mp[x] += 1;
    }
    int ans = 0;
    for(auto [_,sz] : mp) ans += (sz & 1);
    cout << ans << "\n";
    return 0;
}
