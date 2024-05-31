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
int root;
map<int,int> lson,rson;

string dfs(int u){
    vector<string> vec(4);
    if(!lson.count(u) && !rson.count(u)) {
        vec[0] = "Leaf";
        vec[2] = " " + to_string(u);
    }else{
        vec[0] = "Node";
        vec[2] = " " + to_string(u);
        if(lson.count(u)) vec[1] = " (" + dfs(lson[u]) + ")";
        if(rson.count(u)) vec[3] = " (" + dfs(rson[u]) + ")";
    }
    string res = ""; for(auto &s : vec) res += s;
    return res;
}

void solve(){
    cin>>root;
    int u,l,r; while(cin>>u>>l>>r){
        if(l != -1) lson[u] = l;
        if(r != -1) rson[u] = r;
    }
    cout << dfs(root) << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
