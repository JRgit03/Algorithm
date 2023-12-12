#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> path;

void solve1(){
    function<void(int)> dfs = [&](int i) -> void {
        if(i == n + 1){
            for(auto x : path) cout << x << " "; 
            cout << "\n";
        }
        
        dfs(i+1);

        path.push_back(i);
        dfs(i+1);
        path.pop_back();   
    }
}

void solve2(){
    for(int i=0;i<(1<<n);i++){
        vector<int> ans;
        for(int j=0;j<n;j++){
            int x = (i >> j) & 1;
            if(x) ans.push_back(j+1);
        }
        for(auto x : path) cout << x << " "; 
        cout << "\n";
    }
}

int main(){
    cin>>n;
    srand(time(0));
    rand() % 2 ? solve1() : solve2()    
    return 0;
}
