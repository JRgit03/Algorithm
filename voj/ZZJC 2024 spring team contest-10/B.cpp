#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<string> g[22]; 

void solve(){
    int n; cin>>n;
    g[1] = {"1"};
    for(int i=2;i<=n;i++){
        for(int j=0;j<g[i-1].size();j++){
            auto &s = g[i-1][j]; int sz = g[i-1].size();
            if((j + 1) & 1) {
                for(int j=i-1;j>=0;j--) g[i].push_back(s.substr(0, j) + to_string(i) + s.substr(j));
            }else{
                for(int j=0;j<=i-1;j++) g[i].push_back(s.substr(0, j) + to_string(i) + s.substr(j));
            }
        }
    }
    for(auto &s : g[n])
        for(int i=0;i<s.length();i++)
            cout << s[i] << " \n"[i == s.length() - 1];
}

signed main(){
    solve();
    return 0;
}

/*
    n = 1
    1 
    
    n = 2
    1 2
    2 1

    n = 3
    1 2 3
    1 3 2
    3 1 2
    3 2 1
    2 3 1
    2 1 3

    n的合法全排列可由n-1的合法全排列得到  
    n-1 => n 从右往左插入 再从左往右插入
*/