#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e6 + 10;

void solve(){
    int n; cin>>n;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int x; cin>>x; mp[x] += 1;
    }
    // cnt1表示值个数为1的数量, cnt2表示值个数超过2的部分的数量
    // cnt1不一定要修改 cnt2必须修改
    int ans = 0, cnt1 = 0, cnt2 = 0;
    for(auto &[v, sz] : mp){
        if(sz == 2) continue;
        else if(sz == 1) cnt1 += 1;
        else if(sz > 2) cnt2 += sz - 2;
    }
    if(cnt1 >= cnt2) ans = (cnt1 - cnt2) / 2 + cnt2;
    else ans = cnt2;
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
