#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 10;
int n,m;
char g[N][N];

set<pair<int,int>> st2 = {{1,1}, {3,1}};
set<pair<int,int>> st1 = {{1,0}, {1,1}, {2,0}, {3,0}, {3,1}, {4,0}, {4,1}};
set<pair<int,int>> st0 = {{1,1},{3,1},{3,2}, {4,1}, {4,2}};
vector<set<pair<int,int>>> st = {st0, st1, st2};

int check(int k,int x,int y,int type){
    int suc = 1;
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            if(st[k].count({i,j})){
                if(g[i + x][j + y] == '#') suc = 0;
            }else{
                if(g[i + x][j + y] == '.') suc = 0;
                if(type == 1) g[i + x][j + y] = '.';
            }
        }
    }
    return suc;
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)   
        for(int j=1;j<=m;j++)
            cin>>g[i][j];
    vector<int> ans(3);
    for(int i=n-5+1;i>=1;i--){
        for(int j=m-3+1;j>=1;j--){
            if(g[i][j] == '#'){
                if(check(2,i,j,0)){
                    ans[2] += 1;
                    check(2,i,j,1);
                }else if(check(1,i,j,0)){
                    ans[1] += 1;
                    check(1,i,j,1);
                }else if(check(0,i,j,0)){
                    ans[0] += 1;
                    check(0,i,j,1);
                }
            }
        }
    }
    for(auto &x : ans) cout << x << " ";
	return 0;
}