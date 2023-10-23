#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    vector<string> g(n);
    for(int i=0;i<n;i++) cin>>g[i];
    int ans = 0;
    int dx[8] = {-1,-1,-1,0,1,1,1,0};
    int dy[8] = {-1,0,1,1,1,0,-1,-1};
    function<void(int,int)> dfs = [&](int x,int y) -> void {
        if(x < 0 || x >= n || y < 0 || y >= m) return;
        if(g[x][y] == '.') return;
        g[x][y] = '.';
        for(int i=0;i<8;i++)
            dfs(x+dx[i],y+dy[i]);
    };
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(g[i][j] == '#'){
                dfs(i,j);
                ans += 1;
            }
    cout << ans << "\n";
    return 0;
}
