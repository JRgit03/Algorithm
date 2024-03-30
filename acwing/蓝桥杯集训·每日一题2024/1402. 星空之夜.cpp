#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 110;
int n,m;
int vis[N][N];
string g[N];

int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};

char ch = 'a' - 1;
vector<pair<char,double>> mp;

char getMp(double h){
    for(auto [c,chash] : mp)    
        if(fabs(h - chash) <= 1e-8)
            return c;
    mp.push_back({++ch, h});
    return ch;
}

// 一个图像只与图片像素点之间的相对位置有关！ res = 两点之间距离之和
double calcHash(vector<pair<int,int>> &path){
    double res = 0; int sz = path.size();
    for(int i=0;i<sz;i++){
        for(int j=i+1;j<sz;j++){
            auto [a,b] = path[i];
            auto [c,d] = path[j];
            // res += (c - a) * (c - a) + (d - b) * (d - b); 容易哈希碰撞
            res += sqrt((c - a) * (c - a) + (d - b) * (d - b));
        }
    }
    return res;
}

void bfs(int i,int j){
    queue<pair<int,int>> q;
    vis[i][j] = 1;
    q.push({i,j});
    vector<pair<int,int>> path;
    while(q.size()){
        auto [x,y] = q.front(); q.pop();
        path.push_back({x,y});

        for(int k=0;k<8;k++){
            int u = x + dx[k], v = y + dy[k];
            if(u < 0 || u >= n || v < 0 || v >= m) continue;
            if(vis[u][v]) continue;
            if(g[u][v] != '1') continue;
            vis[u][v] = 1;
            q.push({u,v});
        }
    }

    char c = getMp(calcHash(path));
    for(auto [x,y] : path) g[x][y] = c;
}

void solve(){
    cin>>m>>n;
    for(int i=0;i<n;i++) cin>>g[i];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(g[i][j] == '1')
                bfs(i,j);
                
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << g[i][j];
        } 
        cout << "\n";
    }
}

signed main(){
    solve();
    return 0;
}
