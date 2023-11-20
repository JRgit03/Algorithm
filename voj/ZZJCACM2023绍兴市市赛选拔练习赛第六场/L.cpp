#include <bits/stdc++.h>
#define int long long
using namespace std;

int t;

struct Node{
    string s;
    int w;
    
    bool operator < (const Node & t) const {
        if(w != t.w) return w > t.w;
        return s < t.s;
    }
};

void solve(){
    int n,m; cin>>n>>m;
    vector<Node> vec;
    for(int i=0;i<n;i++){
        string s; int w; cin>>s>>w;
        vec.push_back({s,w});
    }
    sort(vec.begin(),vec.end());
    int ans = 0;
    for(int i=0;i<m;i++){
        ans += (m-(i+1)+1) * vec[i].w;
    }
    cout << ans;
    for(int i=0;i<m;i++) cout << " " << vec[i].s;
    if(t) cout << "\n";
}

signed main(){
    cin>>t;
    while(t--)
        solve();
    return 0;
}
