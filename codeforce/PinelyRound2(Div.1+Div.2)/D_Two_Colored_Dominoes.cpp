#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve(){
    int n,m;cin>>n>>m;
    map<int,int> row,col;
    vector<vector<char>> g(n+1,vector<char>(m+1));
    vector<vector<bool>> vis(n+1,vector<bool>(m+1));
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++){
            char &c = g[i][j]; cin>>c;
            if(c != '.') row[i]++ , col[j]++;
        }
    for(int i=1;i<=n;i++) 
        if(row[i] & 1){
            cout << -1 << "\n";
            return;
        }
    for(int i=1;i<=m;i++) 
        if(col[i] & 1){
            cout << -1 << "\n";
            return;
        }
    set<int> st1,st2;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(vis[i][j] || g[i][j] == '.') continue;
            if(g[i][j] == 'L'){
                if(!st1.count(j)){
                    st1.insert(j);
                    g[i][j] = 'W' , g[i][j+1] = 'B';
                    vis[i][j] = vis[i][j+1] = 1;
                }else{
                    st1.erase(st1.lower_bound(j));
                    g[i][j] = 'B' , g[i][j+1] = 'W';
                    vis[i][j] = vis[i][j+1] =1;
                }
            }else{
                if(!st2.count(i)){
                    st2.insert(i);
                    g[i][j] = 'W' , g[i+1][j] = 'B';
                    vis[i][j] = vis[i+1][j] = 1;
                }else{
                    st2.erase(st2.lower_bound(i));
                    g[i][j] = 'B' , g[i+1][j] = 'W';
                    vis[i][j] = vis[i+1][j] = 1;
                }
            }
        }
    
    if(st1.size() || st2.size()){
        cout << -1 << "\n";
        return;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
             cout << g[i][j];
        }
        cout << "\n";
    }   
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--) solve();
    return 0;
}
