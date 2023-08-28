#include <bits/stdc++.h>
using namespace std;

int t;
int dx[] = {1,-1,-1,1};
int dy[] = {-1,-1,1,1};

map<string,int> dirMp = {{"DL",0},{"UL",1},{"UR",2},{"DR",3}};

void solve(){
    int n,m,a,b,c,d;string dirStr;
    cin>>n>>m>>a>>b>>c>>d>>dirStr;

    int dir = dirMp[dirStr];
    vector<vector<int>> g(n+1,vector<int>(m+1));
    int x=a,y=b,step=0;

    g[x][y]++;
    if(c==a && d==b) {cout << 0 << "\n"; return;}

    for(;;step++){
        while(true){
            x += dx[dir] , y += dy[dir];

            if(x<1 || x>n || y<1 || y>m){
                x -= dx[dir] , y -= dy[dir];
                if(!dir) dir = 2;
                else if(dir==1) dir = 3;
                else if(dir==2) dir = 0;
                else if(dir==3) dir = 1;
                break;
            }
            
            g[x][y]++;

            // cout << x << " " << y << "\n";

            if(x==c && y==d) {cout << step << "\n"; return;}

            if(g[x][y] > 4) {cout << -1 << "\n"; return;}

            if(!dir && (x==n || y==1)){
                if(x==n && y==1) {
                    dir = 2;break;
                }
                if(x==n) dir = 1;
                else dir = 4;
                break;
            }else if(dir==1 && (x==1 || y==1)){
                if(x==1 && y==1) {
                    dir = 3;break;
                }
                if(x==1) dir = 0;
                else dir = 2;
                break; 
            }else if(dir==2 && (x==1 || y==n)){
                if(x==1 && y==n) {
                    dir = 0;break;
                }
                if(x==1) dir = 3;
                else dir = 1;
                break;
            }else if(dir==3 && (x==n || y==n)){
                if(x==n && y==n) {
                    dir = 1;break;
                }
                if(x==n) dir = 2;
                else dir = 0;
                break;
            }
        }
    }
    cout << -1 << "\n";
}

int main(){
    cin>>t;while(t--)solve();
    return 0;
}
