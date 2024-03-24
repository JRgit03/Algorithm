#include <bits/stdc++.h>
using namespace std;
int n;
int num[110];

set<pair<int,int>> st;
vector<pair<int,int>> ans;

void dfs(int i){
    if(i == 3){
        int v1 = num[1], v2 = num[2];
        if(v1 == 0) v2 = 1;
        int x = gcd(v1, v2); v1 /= x; v2 /= x;
        st.insert({v1,v2});
        return; 
    }

    for(int j=(i == 1 ? 0 : max(1, num[1]));j<=n;j++){
        num[i] = j;
        dfs(i + 1);
    }
}

void solve(){
    cin>>n;
    dfs(1);
    for(auto [a,b] : st) ans.push_back({a,b});
    sort(ans.begin(), ans.end(), [&](auto &p, auto &q){
        return p.first * q.second < q.first * p.second;
    });
    for(auto [a,b] : ans) cout << a << "/" << b << "\n";
}

signed main(){
    solve();
    return 0;
}
