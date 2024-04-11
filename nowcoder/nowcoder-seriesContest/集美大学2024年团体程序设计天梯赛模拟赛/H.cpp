#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e3 + 10;
int n,m;
char g[N][N];
int g2[N][N]; // 0未操作 1荷花 2水仙 3苍月草

int dx[] = {-1,-1,-1,0,1,1,1,0};
int dy[] = {-1,0,1,1,1,0,-1,-1};

// 点xy是否有房屋限制
int check(int x,int y){
    int f = 0;
    for(int k=0;k<8;k++){
        int u = x + dx[k], v = y + dy[k];
        if(u >= 1 && u <= n && v >= 1 && v <= m && g[u][v] == 'H'){
            f = 1;
        } 
    }
    return f;
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>g[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(g[i][j] == 'L'){
                int cnt1 = 0;
                for(int k=0;k<8;k++){
                    int u = i + dx[k], v = j + dy[k];
                    if(u >= 1 && u <= n && v >= 1 && v <= m && g[u][v] == 'G' && !check(u,v)){
                        // 湖泊周围没有限制的青草块
                        g2[u][v] = 2;
                    }
                    if(u >= 1 && u <= n && v >= 1 && v <= m && g[u][v] == 'L'){
                        cnt1 += 1;
                    } 
                }
                if(cnt1 == 8) g2[i][j] = 1;
            }
        }    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g[i][j] == 'G' && !check(i,j) && g2[i][j] == 0) g2[i][j] = 3;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(g2[i][j] == 0) cout << g[i][j];
            else if(g2[i][j] == 1) cout << "S";
            else if(g2[i][j] == 2) cout << "N";
            else cout << "B";
        }
        cout << "\n";
    }
}

signed main(){
    solve();
    return 0;
}
