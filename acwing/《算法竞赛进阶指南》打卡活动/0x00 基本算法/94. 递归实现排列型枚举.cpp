#include <bits/stdc++.h>
using namespace std;
int n;
int vis[11];
vector<int> path;

void dfs(int i){ //枚举第i个选择的数字
    if(i == n + 1){
        for(auto x : path) cout << x << " "; cout << "\n";
        return;
    }
    for(int k=1;k<=n;k++){
        if(!vis[k]){
            vis[k] = 1;
            path.push_back(k);
            dfs(i+1);
            path.pop_back();
            vis[k] = 0;
        }
    }
}

int main(){
    cin>>n;
    dfs(1);    
    return 0;
}
