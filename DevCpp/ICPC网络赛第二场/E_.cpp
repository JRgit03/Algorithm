#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n,m;
int ans[N];
pair<int,int> q[N*50]; int hh,tt;
vector<int> g[N];
vector<int> h[N];

int main(){
    memset(ans,-1,sizeof ans);
    cin>>n>>m;
    
    for(int i=2;i<=n;i++){
        int u; cin>>u;
        g[i].push_back(u);
    }

    // for(int i=1;i<=n;i++)
    //     for(auto j : g[i])
    //         cout << i << " " << j << "\n";
    // cout << "=========" << "\n";

    hh = 1 , tt = 0;
    vector<int> vec;

    for(int i=1;i<=m;i++){
        int a,b; cin>>a>>b;   
        if(a == 1 || b == 1){
            if(a == 1){
                q[++tt] = {b,1};
            }else{
                q[++tt] = {a,1};
            }
        }
        h[a].push_back(b);
        h[b].push_back(a);
    }

    ans[1] = 0;
    
    int l = hh , r = tt;

    while(l<=r){
        while(hh <= tt){
            auto [u,step] = q[hh++];

            if(ans[u] != -1) continue;
            ans[u] = step;

            // cout << u << " " << step << "\n";

            for(auto v : g[u])
                q[++tt] = {v,step};
        }
        int tmp = tt; r = tt; 
        while(l <= tmp){
            auto [u,step] = q[l++];

            for(auto v : h[u])
                if(ans[v] == -1){
                    q[++r] = {v,step+1};
                }
        }
        hh = l , tt = r;
    }

    for(int i=2;i<=n;i++) cout << ans[i] << " ";

    return 0;
}