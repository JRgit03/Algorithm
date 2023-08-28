#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef pair<int,int> PII;
const int N = 1010;
int n,m;
int sumw;
char g[N][N];
bool st[N][N];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

bool bfs(int x,int y){
    queue<PII> q;
    st[x][y] = true;
    q.push({x,y});
    int cnt = 1;

    while(q.size()){
        auto [x,y] = q.front() ; q.pop();
        
        for(int i=0;i<4;i++){
            int u = x + dx[i] , v = y + dy[i];
            if(u>=1&&u<=n&&v>=1&&v<=m&&!st[u][v]&&g[u][v]=='.'){
                st[u][v] = true; cnt++;
                q.push({u,v});
            }
        }
    }

    sumw += cnt;
    bool flag = true;
    
    if(x+3<=n&&x>=1&&y-1>=1&&y+2<=m){
        for(int i=0;i<=3;i++)
            for(int j=-1;j<=2;j++){
                if((i==0&&j==-1)||(i==0&&j==2)||(i==3&&j==-1)||(i==3&&j==2)){
                    if(g[x+i][y+j]=='.') flag = false;
                }else{
                    if(g[x+i][y+j]=='#') flag = false;
                }
            }
    }else flag = false;

    return cnt==12 && flag;
}

int main(){
    IOS;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>g[i][j];
    int white = 0 , black = 0;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(g[i][j]=='.' && !st[i][j]){
                bool flag = bfs(i,j);
                if(flag) white++;
            }
        }
    black = n*m - sumw;
    //cout << white << " " << black << "\n";

    int res = (100*white - black) / 54;
    cout << res << " " << white - 2*res << "\n";
    return 0;
}
