#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair<int,int> PII;

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void solve(){
    int n,m; cin>>n>>m;
    vector<vector<int>> g(n+1, vector<int>(m+1, 0));
    vector<vector<int>> vis(n+1, vector<int>(m+1, 0));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            char c; cin>>c;
            g[i][j] = c - '0';
        }
    int ans1 = 0, ans2 = 0;
    auto bfs = [&](int sx,int sy){
    	//cout << sx << " " << sy << "\n";
    	int f = 0;
    	queue<PII> q;
    	q.push({sx,sy});
		vis[sx][sy] = 1;
    	
		while(q.size()){
    		auto [x,y] = q.front(); q.pop();
    		f |= (g[x][y] > 1);
    		
    		for(int i=0;i<4;i++){
    			int u = x + dx[i], v = y + dy[i];
    			if(u < 1 || u > n || v < 1 || v > m) continue;
    			if(vis[u][v]) continue;
    			if(g[u][v] == 0) continue;
				vis[u][v] = 1;
    			q.push({u,v});
			}
		}
		ans1 += 1, ans2 += f;
	};
	
	for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(g[i][j] != 0 && !vis[i][j])
            	bfs(i,j);
            	
	cout << ans1 << " " << ans2 << "\n";
}

int main(){
    IOS;
    solve();
    return 0;
}
