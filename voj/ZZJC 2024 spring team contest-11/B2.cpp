#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
constexpr int N = 1e6 + 10, mod = 998244353;

#define int long long
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int n,m;
int l[N];
vector<int> g[N];

struct Node{
    int w, t;
    bool operator < (const Node& o) const {
        return t < o.t;
    }
};

void Sakuya()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++) g[i].clear();
    for(int i=1;i<=m;i++) cin>>l[i];
    vector<Node> all;
    for(int i=1;i<=n;i++){
        int a,b; cin>>a>>b; // b <= m
        g[b].push_back(a); // b-type  a-val
    }
    for(int i=1;i<=m;i++){
        sort(g[i].begin(), g[i].end(), greater<int>());
        if(g[i].size() < l[i]) g[i].clear();
        else{
            int sum = 0;
            for(int j=0;j<l[i];j++) sum += g[i][j];
            all.push_back({sum, l[i]});
            for(int j=l[i];j<g[i].size();j++) all.push_back({g[i][j], j+1});
        }       
    }
    sort(all.begin(), all.end());
    // for(auto &[a,b] : all) cout << a << " " << b << "\n"; cout << "\n";
    vector<pair<int,int>> res;
    for(int i=0;i<all.size();i++){
        int j = i, s = 0, t = all[i].t;
        while(j < all.size() && all[i].t == all[j].t){
            s += all[j].w;
            j += 1;
        }
        i = j - 1;
        res.push_back({s,t});
    }
    sort(res.begin(), res.end(), [&](auto &p, auto &q){
        return p.second < q.second;
    });
    int ans1 = 0, ans2 = 1, s = 0;
    for(auto [a,b] : res){
        s += a;
        // cout << ans1 * b << " " << s * ans2 << "\n";
        if(ans1 * b < s * ans2){
            ans1 = s, ans2 = b;
        }
    }
    cout << ans1 / __gcd(ans1, ans2) << "/" << ans2 / __gcd(ans1, ans2) << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    for (cin >> T; T -- ; )
        Sakuya();

}