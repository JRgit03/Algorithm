#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> path;

void dfs(int i,int j){
    
    if(n-i+1 < j) return;
    
    if(i == n + 1 || j == 0){
        for(auto x : path) cout << x << " "; cout << "\n";
        return;
    }
    
    path.push_back(i);
    dfs(i+1,j-1);
    path.pop_back();
    
    dfs(i+1,j);
}

int main(){
    cin>>n>>m;
    dfs(1,m);    
    return 0;
}
