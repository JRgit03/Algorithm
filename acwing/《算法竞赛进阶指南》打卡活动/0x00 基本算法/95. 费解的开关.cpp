#include <bits/stdc++.h>
using namespace std;
int T;
string g[5],t[5];

void turn(int x,int y){
    int dx[5] = {-1,0,1,0,0}, dy[5] = {0,1,0,-1,0};
    for(int i=0;i<5;i++){
        int u = x + dx[i], v = y + dy[i];
        if(u < 0 || u >= 5 || v < 0 || v >= 5) continue;
        g[u][v] = (g[u][v] == '0' ? '1' : '0');
    }
}

void solve(){
    for(int i=0;i<5;i++) cin>>g[i]; 
    for(int i=0;i<5;i++) t[i] = g[i];
    int ans = INT_MAX;
    for(int i=0;i<(1<<5);i++){
        for(int j=0;j<5;j++) g[j] = t[j];
        int op = 0;
        for(int j=0;j<5;j++) if((i >> j) & 1) turn(0,j), op += 1;
        for(int j=1;j<5;j++){
            for(int k=0;k<5;k++){
                if(g[j-1][k] == '0'){
                    turn(j,k); op += 1;
                }
            }
        }
        bool flag = true;
        for(int j=0;j<5;j++) if(g[4][j] == '0') flag = false;
        if(flag && op <= 6) ans = min(ans, op); 
    }
    if(ans == INT_MAX) ans = -1;
    cout << ans << "\n";
}

int main(){
    cin>>T; 
    while(T--)
        solve();    
    return 0;
}

// 枚举第一行的所有按法
// 如果第一行的状态是确定的 => 接下来的操作序列是一定的 
