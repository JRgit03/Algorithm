#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

map<char,int> mp = {{'X',0},{'O',1},{'+',2}};
map<int,char> ump = {{0,'X'},{1,'O'},{2,'+'}};
char g[3][3];

void solve(){
	vector<int> p(3);
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin>>g[i][j];

    int win = -1;
    auto check = [&](int x,int y){
        if(g[x][y] == '.') return false;
        if(g[x][0] == g[x][1] && g[x][1] == g[x][2]) return true;
        if(g[0][y] == g[1][y] && g[1][y] == g[2][y]) return true;
        if(x==1 && y==1){
            if(g[0][0] == g[1][1] && g[1][1] == g[2][2]) return true;
            if(g[0][2] == g[1][1] && g[1][1] == g[2][0]) return true;
        }
        return false;
    };

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(check(i,j)){
                p[mp[g[i][j]]] = 1; win = mp[g[i][j]];
            }
    
    if(accumulate(p.begin(),p.end(),0) != 1 )  {
        cout << "DRAW" << "\n"; return;
    }

    cout << ump[win] << "\n"; return;
}

int main(){
	IOS;
	int t;cin>>t;
    while(t--)solve();
	return 0;
}