/**
 * 题意：n个校友字符串 m个来宾 
 * output: 统计来宾中的校友个数 + 输出最年长的来宾校园 (存在) / 最年长来宾 (不存在校友) 
 */
#include <bits/stdc++.h>
using namespace std;

bool cmp(string &p, string &q){
    return p.substr(6,7) < q.substr(6,7);
}

int main(){
    int n; cin>>n;
    set<string> st;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        st.insert(s);
    } 
    int m; cin>>m;
    vector<string> v1,v2;
    for(int i=0;i<m;i++){
        string s; cin>>s;
        if(st.count(s)) v1.push_back(s);
        else v2.push_back(s);
    }
    sort(v1.begin(),v1.end(),cmp);
    sort(v2.begin(),v2.end(),cmp);
    cout << v1.size() << "\n";
    cout << (v1.size() ? v1[0] : v2[0]) << "\n";
    return 0;
}
