#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;
int max(int a,int b){ return (a > b ? a : b);}
int min(int a,int b){ return (a < b ? a : b);}

const int N = 5e4 + 10, up = 1e9;
int n,m;
int vis[N];
map<pair<int,int>, vector<int>> mp; // {{{x,y},{id1,id2,...}}...}

int x[N],y[N],r[N];

void dfs(int a,int b,int c){
    for(int x=max(0, a-c);x<=min(up, a+c);x++){
        for(int y=max(0,b-c);y<=min(up, b+c);y++){
            if(mp.count({x,y}) && (a - x) * (a - x) + (b - y) * (b - y) <= c * c){
                int maxr = -1;
                for(auto &id : mp[{x,y}]) {
                    maxr = max(maxr, r[id]);
                    vis[id] = 1;
                }
                mp.erase({x,y});
                dfs(x,y,maxr);
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>x[i]>>y[i]>>r[i];
        mp[{x[i], y[i]}].push_back(i);
    }
    for(int i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c;
        for(int x=max(0, a-c);x<=min(up, a+c);x++){
            for(int y=max(0,b-c);y<=min(up, b+c);y++){
                if(mp.count({x,y}) && (a - x) * (a - x) + (b - y) * (b - y) <= c * c){
                    int maxr = -1;
                    for(auto &id : mp[{x,y}]) {
                        maxr = max(maxr, r[id]);
                        vis[id] = 1;
                    }
                    mp.erase({x,y});
                    dfs(x,y,maxr);
                }
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) if(vis[i]) {
        ans += 1;
    }
    cout << ans << "\n";
}

// r <= 10 !!! 
signed main(){
	IOS;
	solve();
	return 0;
} 

/*
2 1
2 2 4
4 4 2
0 0 5
*/
