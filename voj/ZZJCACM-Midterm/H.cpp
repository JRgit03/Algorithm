#include <bits/stdc++.h>
using namespace std;
const int N = 33;
int n;
int g[N][N];

int dx[] = {-1,0,1,0} , dy[] = {0,1,0,-1};

void dfs(int x,int y){
    g[x][y] = 3;
    for(int i=0;i<4;i++){
        int u = x + dx[i] , v = y + dy[i];
        if(u>=1&&u<=n&&v>=1&&v<=n&&!g[u][v])
            dfs(u,v);
    }
}

void fill(int x,int y){
    g[x][y] = 2;
    for(int i=0;i<4;i++){
        int u = x + dx[i] , v = y + dy[i];
        if(u>=1&&u<=n&&v>=1&&v<=n&&!g[u][v])
            fill(u,v);
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)   
            cin>>g[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(i==1 || i==n || j==1 || j==n){
                if(!g[i][j]){
                    dfs(i,j);
                }
            }
        }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(!g[i][j])
                fill(i,j);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cout << (g[i][j]==3 ? 0 : g[i][j]) << " \n"[j==n];
        }
    return 0;
}
