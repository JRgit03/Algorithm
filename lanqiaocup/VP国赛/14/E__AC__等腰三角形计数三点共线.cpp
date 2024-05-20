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
int n;
int x[N],y[N];
set<pair<int,int>> st;

int get(int i,int j){
    int dx = x[i] - x[j], dy = y[i] - y[j];
    return dx * dx + dy * dy;
}

// 整点不可能出现等边三角形！
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>x[i]>>y[i];
        st.insert({x[i], y[i]});
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        map<int,int> mp; int cnt = 0;
        for(int j=1;j<=n;j++){
            if(i == j) continue;
            int len = get(i, j);
            ans += mp[len];
            mp[len] += 1;  
            // 处理三点共线 对称点
            int u = 2 * x[i] - x[j], v = 2 * y[i] - y[j];
            if(st.count({u,v})) cnt += 1;
        } 
        // 共线情况会重复一次
        ans -= cnt / 2; 
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
