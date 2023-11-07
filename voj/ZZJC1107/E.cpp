#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n;
bool vis[maxn];
int to[maxn]; // to[i]: i -> to[i]

int find(int u){
    vis[u] = true;
    int fa = to[u];
    if(!vis[fa]) return find(fa);
    return fa;
} 

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>to[i];
    int x = find(1);
    memset(vis,false,sizeof vis);
    vector<int> ans;
    for(int u=x;!vis[u];u=to[u]) {
        vis[u] = true;
        ans.push_back(u);
    }
    cout << ans.size() << "\n";
    for(auto x : ans) cout << x << " ";
    return 0;
}
