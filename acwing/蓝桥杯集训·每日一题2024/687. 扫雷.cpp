#include <bits/stdc++.h>
using namespace std;
const int N = 3e2 + 10;
int n;
string g[N];
int cnt[N][N];

int dx[] = {-1,-1,-1,0,1,1,1,0};
int dy[] = {-1,0,1,1,1,0,-1,-1};

void solve(int T){
    cin>>n;
    for(int i=0;i<n;i++) cin>>g[i];
    memset(cnt, 0, sizeof cnt);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(g[i][j] == '*'){
                for(int k=0;k<8;k++){
                    int u = i + dx[k], v = j + dy[k];
                    if(u < 0 || u >= n || v < 0 || v >= n) continue;
                    if(g[u][v] == '*') continue;
                    cnt[u][v] += 1;
                }
            }
        }
    int ans = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(cnt[i][j] == 0 && g[i][j] == '.'){
                ans += 1;
                queue<pair<int,int>> q;
                q.push({i,j});
                g[i][j] = '#';
                while(q.size()){
                    auto [x,y] = q.front(); q.pop();
                    for(int k=0;k<8;k++){
                        int u = x + dx[k], v = y + dy[k];
                        if(u < 0 || u >= n || v < 0 || v >= n) continue;
                        if(g[u][v] != '.') continue;
                        g[u][v] = '#';
                        if(cnt[u][v] == 0) q.push({u,v});
                    }
                }
            }
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ans += (g[i][j] == '.');
    printf("Case #%d: %d\n", T, ans);
}

signed main(){
    int t; cin>>t;
    for(int i=1;i<=t;i++) solve(i);
    return 0;
}
