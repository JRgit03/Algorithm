#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n,m;
string s; 
int c[maxn];

int main(){
    cin>>n>>m;
    cin>>s;
    vector<pair<char,int>> vec[m];
    for(int i=0;i<n;i++) {
        cin>>c[i]; c[i]--;
        vec[c[i]].push_back({s[i],i});
    }
    vector<pair<char,int>> ans;
    for(auto v : vec){
        auto ed = v.back().first;
        for(int i=v.size()-2;i>=0;i--) v[i+1].first = v[i].first;
        v.front().first = ed;
        for(auto item : v) ans.push_back(item);
    }
    sort(ans.begin(),ans.end(),[&](auto &a,auto &b){
       return a.second < b.second; 
    });
    for(auto [c,id] : ans) cout << c;
    return 0;
}
