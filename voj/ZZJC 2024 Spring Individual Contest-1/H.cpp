#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    stack<int> stk;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        char c = s[i - 1];
        if(c == '-') ans.push_back(i);
        else if(c == '(') stk.push(i);
        else if(c == ')'){
            ans.push_back(i);
            ans.push_back(stk.top()); stk.pop();
        }
    }
    for(auto &x : ans) cout << x << " "; 
}

signed main(){
    solve();
    return 0;
}
