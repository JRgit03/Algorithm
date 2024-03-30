#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n; getchar();
    string s; getline(cin, s);
    int len = s.length();
    vector<char> ans[n];
    for(int i = 0, j = 0;i < len; i += 1){
        ans[j].push_back(s[i]);
        j = (j + 1) % n;
    }
    for(int i=0;i<n;i++){
        reverse(ans[i].begin(), ans[i].end());
        if(ans[i].size() != ans[0].size()) cout << " ";
        for(auto &c : ans[i]) cout << c;
        if(i < n - 1) cout << "\n";
    }
    return 0;
}