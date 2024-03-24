#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node{
    int t,p,num;
    bool operator < (const Node& o) const {
        if(t != o.t) return t < o.t;
        return (t == 0 ? p < o.p : p > o.p);
    }
};

void solve(){
    int n; cin>>n;
    map<int,int> mp1,mp2;
    for(int i=0;i<n;i++){
        string op; int a,b; cin>>op>>a>>b;
        if(op[0] == 'B') mp1[a] += b;
        else mp2[a] += b;
    }
    vector<Node> vec;
    for(auto [a,b] : mp1) vec.push_back({0,a,b});
    for(auto [a,b] : mp2) vec.push_back({1,a,b});
    sort(vec.begin(), vec.end());
    cout << vec.size() << "\n";
    for(auto [t,a,b] : vec) cout << (t == 0 ? "BUY" : "SELL") << " " << a << " " << b << "\n";
}

signed main(){
    solve();
    return 0;
}
