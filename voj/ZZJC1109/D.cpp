/**
 * 模拟 贪心：区间外的'?'均置为a
 * Difficulty: 846
 * https://atcoder.jp/contests/abc076/tasks/abc076_c
 */
#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    string s,t; cin>>s>>t;
    n = s.length(), m = t.length();
    if(m > n) {
        cout << "UNRESTORABLE" << "\n";
        return 0;
    }
    vector<string> ans;
    for(int i=0;i+m-1<n;i++){ // 枚举左端点
        bool f = 1;
        for(int j=0;j<m;j++) f &= (s[i+j] == '?' || s[i+j] == t[j]); // 枚举偏移量 判断当前子串是否合法
        if(f){ 
            string ss = s;
            for(int j=0;j<n;j++) if(ss[j] == '?') ss[j] = 'a';
            for(int j=0;j<m;j++) ss[i+j] = t[j];
            ans.push_back(ss);
        }
    }
    sort(ans.begin(),ans.end());
    if(ans.size() == 0) {
        cout << "UNRESTORABLE" << "\n";
        return 0;
    }
    cout << ans[0] << "\n";
    return 0;
}
