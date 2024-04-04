#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n,m;
int l[N];
vector<int> g[N];

void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        g[i].clear(); cin>>l[i];
    }
    for(int i=1;i<=n;i++){
        int a,b; cin>>a>>b;
        g[b].push_back(a);
    }
    vector<array<int,2>> all; // {{val,层数}...}
    for(int i=1;i<=m;i++){
        if(g[i].size() < l[i]) continue;
        sort(g[i].begin(), g[i].end(), greater<int>() );
        int sum = 0;
        for(int j=0;j<l[i];j++) sum += g[i][j];
        all.push_back({sum, l[i]});
        for(int j=l[i];j<g[i].size();j++) all.push_back({g[i][j], j+1});
    }
    sort(all.begin(), all.end(), [&](auto &p, auto &q){
        return p[1] < q[1];
    });
    // for(auto v : all) cout << v[0] << " " << v[1] << "\n"; cout << "\n";
    int ans1 = 0, ans2 = 1, sum = 0; // ans1 / ans2
    for(int i=0;i<all.size();i++){
        int j = i;
        while(j<all.size() && all[i][1] == all[j][1]) {
            sum += all[j][0];
            j += 1;
        }
        if(ans1 * all[i][1] <= sum * ans2) {
            ans1 = sum / __gcd(all[i][1], sum);
            ans2 = all[i][1] / __gcd(all[i][1], sum);
        }
        i = j - 1;
    }
    cout << ans1 << "/" << ans2 << "\n";
}

signed main(){
    IOS;
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
