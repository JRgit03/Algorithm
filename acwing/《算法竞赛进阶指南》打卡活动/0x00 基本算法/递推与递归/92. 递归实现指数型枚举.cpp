#include <bits/stdc++.h>
using namespace std;
int n; 
vector<int> path;

// 从i往后选 一共要选择j个
void dfs(int i,int j){
    // cout << i << " " << j << "\n";
    if(n-i+1 < j) return;

    if(j == 0){
        for(auto x : path) cout << x << " "; cout << "\n";
        return;
    }

    for(int k=i;k<=n;k++){
        path.push_back(k);
        dfs(k+1,j-1);
        path.pop_back();
    }
}

int main(){
    cin>>n;
    for(int i=0;i<=n;i++)
        dfs(1,i);
    return 0;
}
