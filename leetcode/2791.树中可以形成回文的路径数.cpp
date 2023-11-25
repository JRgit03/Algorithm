/*
 * @lc app=leetcode.cn id=2791 lang=cpp
 *
 * [2791] 树中可以形成回文的路径数
 */

// @lc code=start
class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();
        long long ans = 0;
        vector<int> g[n];
        for(int i=1;i<n;i++) g[parent[i]].push_back(i);
        map<int,int> cnt; cnt[0] = 1;
        function<void(int,int)> dfs = [&](int u,int path) -> void {
            for(auto v : g[u]){
                int e = 1 << (s[v] - 'a');
                int cur = path ^ e;
                if(cnt.count(cur)) ans += cnt[cur]; // x ^ x = 0
                for(int i=0;i<26;i++){ // 枚举保留的字符
                    int now = cur ^ (1 << i);
                    if(cnt.count(now)){
                        ans += cnt[now];
                    }
                }
                cnt[cur]++;
                dfs(v,cur);
            }
        };
        dfs(0,0);
        return ans;
    }
};
// @lc code=end
// solution:
// 由于一条u->v路径上可以重新排列 => 只关心 字符出现次数的奇偶性
// 要求 u < v => u 和 v 节点的访问顺序没有关系

