#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n,m;
typedef pair<int,int> PII;
map<string, set<PII>> mp; // str -> ids = {{id, lastUp}....}
int last[N]; // last update
string ans[N];

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) last[i] = -1;
    for(int i=1;i<=n;i++) {
        string s; cin>>s;
        mp[s].insert({i,0});
    } 
    for(int i=1;i<=m;i++){
        int op; cin>>op;
        if(op == 1){ 
            string a,b; cin>>a>>b;
            if(a == b) continue;
            // merge mp[a] -> mp[b]
            if(mp[a].size() > mp[b].size()) swap(mp[a], mp[b]); 
            mp[b].insert(mp[a].begin(), mp[a].end());
            mp[a].clear();
        }else{
            int x; string s; cin>>x>>s;
            mp[s].insert({x, i});
        }
    }
    for(auto &[s, st] : mp)
        for(auto &[id, t] : st){
            if(t > last[id]){
                ans[id] = s; 
                last[id] = t;
            }
        }
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
}

signed main(){
    solve();
    return 0;
}
