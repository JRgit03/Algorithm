#include <bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve(){
    int n,m,k; cin>>n>>m>>k;
    vector<int> h(n+1); for(int i=1;i<=n;i++) cin>>h[i];
    vector<int> g[n+1],d(n+1),unlock(n+1);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v) , d[v]++;
    }
    vector<int> f(n+1); // f[i]表示点i的最早开始时间
    int maxt = 0;
    
    queue<int> q;
    for(int i=1;i<=n;i++) 
        if(!d[i]){
            q.push(i); f[i] = h[i];
        }
    
    while(q.size()){
        int u = q.front(); q.pop();
        maxt = max(maxt,f[u]);

        for(auto v : g[u]){
            if(d[v] == ++unlock[v]){
                q.push(v);
            }
            int ed = h[v] , st = f[u] % k;
            if(st <= ed) f[v] = max(f[v] , f[u] + ed - st);
            else if(st > ed) f[v] = max(f[v] , f[u] + k - (st - ed));
        }
    }

    //枚举起点
    map<int,vector<int> > mp;
    for(int i=1;i<=n;i++) 
        if(!d[i])
            mp[f[i]].push_back(i);
         
    auto update = [&](int st){
        queue<int> q;
        q.push(st);

        while(q.size()){
            int u = q.front(); q.pop();
            maxt = max(maxt,f[u]);
            for(auto v : g[u]){
                if(f[v] < f[u]){ //连带推迟
                    f[v] += k;
                    q.push(v);
                }
            }
        }
    };

    int ans = LONG_LONG_MAX;
    for(auto [st,vec] : mp){
        ans = min(ans,maxt-st);
        for(auto s : vec){
            f[s] += k;
            update(s);            
        }
    }
    
    cout << ans << "\n";
}

signed main(){
    IOS;
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
