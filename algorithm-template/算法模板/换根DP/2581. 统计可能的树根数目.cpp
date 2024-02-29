//https://leetcode.cn/problems/count-number-of-possible-root-nodes/description/?envType=daily-question&envId=2024-02-29

// 数据范围1e5

// 题意： 给定一棵无根树 和 一组猜测 如果以u为根的子树 符合至少k个guess 则 ans + 1;
// 每一次猜测： 1.选择不相等的 u,v 要求树中必须存在边u->v 
//             2.u是v的父节点
// 求可能为树根的点数 即 符合至少k个guess的以u为根的点数 数量

// 换根： 先统计一个结果， 再逐步换根求的不同根的结果
// 思路： 考虑换根 观察变化的量
// u v 是 父子 
// 以u为根的树切换到以v为根的树 变化的 只有 edge(u,v)之间的关系

class Solution {
public:

    long long Hash(int u,int v){
        return 1LL * u * 100000 + 1LL * v;
    }

    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        set<long long> st; 
        for(auto &e : guesses){
            st.insert(Hash(e[0], e[1]));
        }
        int n = edges.size(); 
        vector<int> g[n+1];
        for(auto &e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int cnt = 0;
        function<void(int,int)> dfs = [&](int u,int f) -> void {
            for(auto &v : g[u]){
                if(v == f) continue;
                if(st.count(Hash(u,v))) cnt += 1;
                dfs(v,u);
            }
        }; dfs(0,0);
        int ans = 0;
        function<void(int,int,int)> reboot = [&](int u,int f,int sz) -> void {
            ans += (sz >= k);
            for(auto &v : g[u]){
                if(v == f) continue;
                reboot(v,u, sz - st.count(Hash(u,v)) + st.count(Hash(v,u)));
            }
        }; reboot(0,0,cnt);
        return ans;
    }
};

