#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int n,m,t,res;
int sx,sy,fx,fy;
bool warn[N][N] , st[N][N];

int dx[] = {-1,0,1,0} , dy[] = {0,1,0,-1};

void dfs(int x,int y){
    if(x==fx && y==fy){
        res++; return;
    }
    
    for(int i=0;i<4;i++){
        int u = x + dx[i] , v = y + dy[i];
        if(u>=1&&u<=n&&v>=1&&v<=m&&!st[u][v]&&!warn[u][v]){
            st[u][v] = true;
            dfs(u,v);
            st[u][v] = false;
        }
    }
}

int main(){
    cin>>n>>m>>t;
    cin>>sx>>sy>>fx>>fy;
    while(t--){
        int x,y;cin>>x>>y;warn[x][y]=true;
    }
    st[sx][sy] = true;
    dfs(sx,sy);
    st[sx][sy] = false;
    cout << res << "\n";
    return 0;
}
