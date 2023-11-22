// 拓扑排序
// 将字符串覆盖匹配问题 => 有向图的拓扑排序问题
// https://leetcode.cn/problems/stamping-the-sequence/description/
class Solution {
public:
    vector<int> movesToStamp(string s, string t) { // t被覆盖的字符串 
        int n = t.length(), m = s.length();
        vector<int> d(n-m+1,m); // d[i] 以i为匹配起点的 不匹配度数为长度m 共有n-m+1个滑窗.
        vector<int> g[n];
        queue<int> q;
        for(int i=0;i+m-1<n;i++){
            for(int j=0;j<m;j++){
                if(t[i+j] == s[j]){
                    if(--d[i] == 0){ // 以i为滑窗的左端点完全匹配
                        q.push(i);
                    }
                }else g[i+j].push_back(i); // 将不匹配的位置与滑窗的左端点 建边
            }
        }
        vector<int> ans;
        vector<bool> vis(n,false);
        while(q.size()){
            auto u = q.front(); q.pop();
            ans.push_back(u);
            for(int i=0;i<m;i++){
                if(!vis[u + i]){ // 打上标记防止重复访问
                    vis[u + i] = true;
                    for(auto v : g[u+i]){ // 将于u+i关联的不匹配度数均减少1
                        if(--d[v] == 0){
                            q.push(v);
                        }
                    }
                }
            }    
        }
        if((int)ans.size() < n - m + 1) return {};
        // abcbabc abc => ***b*** 原问题等价于 通过abc将原串abcbabc变为*******操作序列 
        // 基于最小匹配后增加更多匹配，而匹配顺序从后往前 同时防止后续操作覆盖之前操作 因此逆序操作
        reverse(ans.begin(),ans.end()); 
        return ans;
    }
};

// E - Stamp
// https://atcoder.jp/contests/abc329/tasks/abc329_e

// #include <bits/stdc++.h>
// using namespace std;
// const int maxn = 2e5 + 10;
// int n,m;
// string s,t;

// int q[maxn],hh = 1,tt;
// int d[maxn];
// bool vis[maxn];
// vector<int> g[maxn];

// int main(){
//     cin>>n>>m>>s>>t;
//     for(int i=0;i<n-m+1;i++) d[i] = m;
//     for(int i=0;i+m-1<n;i++){
//         for(int j=0;j<m;j++){
//             if(s[i+j] == t[j]){
//                 if(--d[i] == 0){
//                     q[++tt] = i;
//                 }
//             }else g[i+j].push_back(i);
//         }
//     }
//     while(hh<=tt){
//         int u = q[hh++]; 
//         for(int i=0;i<m;i++){
//             if(vis[u + i]) continue;
//             vis[u + i] = true;
//             for(auto v : g[u+i]){
//                 if(--d[v] == 0){
//                     q[++tt] = v;
//                 }
//             }
//         }
//     }
//     cout << (tt == n - m + 1 ? "Yes" : "No") << "\n";
//     return 0;
// }
