#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;

void solve(){
    int n,k; cin>>n>>k;
    vector<int> g[n],marked(k); // 0 ~ n-1
    for(int i=0;i<k;i++) cin>>marked[i] , marked[i]--;
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v; u--,v--;
        g[u].push_back(v) , g[v].push_back(u);
    }
    if(k == 1){
        cout << 0 << "\n";
        return;
    }
    vector<int> d1(n,INF),d2(n,INF);
    function<void(int,int,vector<int>&)> dfs = [&](int u,int fa,vector<int> &d) -> void {
        for(auto v : g[u]){
            if(v == fa) continue;
            d[v] = d[u] + 1;
            dfs(v,u,d);
        }
    };
    d1[marked[0]] = 0; dfs(marked[0],-1,d1);
    int a,b,dista,distb; a = b = dista = distb = -1;
    for(int i=0;i<k;i++) {
        if(d1[marked[i]] > dista){
            dista = d1[marked[i]];
            a = marked[i];
        }
    }
    d2[a] = 0; dfs(a,-1,d2);
    for(int i=0;i<k;i++) {
        if(d2[marked[i]] > distb){
            distb = d2[marked[i]];
            b = marked[i];
        }
    }
    // cout << a << " " << b << " " << dista << " " << distb << "\n";
    cout << (distb + 2 - 1) / 2 << "\n";
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
