#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;

signed main(){
    IOS;
    int t; cin>>t;
    for(int T=0;T<t;T++){
        int x,y; cin>>x>>y;
        int mul = x * y;
        vector<pair<int,int>> ans;
        for(int i=1;i<=mul/i;i++){
            if(mul % i == 0){
                int j = mul / i;
                int k1 = __gcd(i,j), k2 = mul / k1;
                if(k1 == x && k2 == y) ans.push_back({i,j});
            }
        }
        sort(ans.begin(), ans.end());
        if(ans.size()) cout << ans[0].first << " " << ans[0].second << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}
