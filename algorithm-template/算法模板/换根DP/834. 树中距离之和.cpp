// https://leetcode.cn/problems/sum-of-distances-in-tree/description/

// 给定一个无向、连通的树。树中有 n 个标记为 0...n-1 的节点以及 n-1 条边 。
// 给定整数 n 和数组 edges edges[i] = [ai, bi]表示树中的节点 ai 和 bi 之间有一条边。
// 返回长度为 n 的数组 answer ，其中 answer[i] 是树中第 i 个节点与所有其他节点之间的距离之和

// 求 以u为根节点与书中所有节点的距离之和

// 换根dp
// 考虑唯一改变的量 求变化量的规律

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n,vector<int>());
        vector<int> sz(n),ans(n);
        //建图
        for(auto &vec : edges){
            int u = vec[0] , v = vec[1];
            g[u].push_back(v) , g[v].push_back(u);
        }
        //子树大小 sz[i]表示已i为根节点的子树大小(包含i) 并且初始化ans[0]的值 自底向上
        function<void(int,int,int)> dfs = [&](int u,int fa,int depth) -> void {
            sz[u] = 1;
            ans[0] += depth;
            for(auto &v : g[u]){
                if(v==fa)continue;
                dfs(v,u,depth+1);
                sz[u] += sz[v];
            }
        }; dfs(0,-1,0); 
        //换根dp 自顶向下
        function<void(int,int)> get = [&](int u,int fa) -> void {
            for(auto &v : g[u]){
                if(v==fa)continue;
                ans[v] = ans[u] + (n - sz[v]) - sz[v];
                get(v,u);
            }
        }; get(0,-1);
        return ans;
    }
};