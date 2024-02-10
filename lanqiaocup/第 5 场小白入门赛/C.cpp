#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n; cin>>n;
    map<int,int> cnt;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        cnt[x * (i + 1)] += 1;
    }
    int ans = 0;
    for(auto [_, sz] : cnt) ans += sz * (sz - 1) / 2;
    cout << ans << "\n";
    return 0;
}
