// 并查集解法
// 好路径：路径两端权值相同 且 中间的节点权值 <= 两端
// => 对于一颗树 根据点的权值从小到大遍历 建边 维护每个连通块内 权值最大的点的个数
// https://leetcode.cn/problems/number-of-good-paths/description/
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        map<int,int> sz[n]; // sz[i][val] = x 表示 leader为i权值为val出现的次数
        int p[n]; for(int i=0;i<n;i++) p[i] = i;
        for(int i=0;i<n;i++) sz[i][vals[i]] = 1;
        function<int(int)> find = [&](int x) -> int {
            if(p[x] != x) p[x] = find(p[x]);
            return p[x];
        };
        int id[n]; for(int i=0;i<n;i++) id[i] = i;
        sort(id,id+n,[&](auto i,auto j){
            return vals[i] < vals[j];
        });
        vector<int> g[n];
        for(auto e : edges){
            int u = e[0], v = e[1];
            g[u].push_back(v); g[v].push_back(u);
        }
        int ans = n;
        for(int i=0;i<n;i++){
            int u = id[i];
            for(auto v : g[u]){
                int pu = find(u), pv = find(v);
                if(pu == pv) continue;
                if(vals[pu] < vals[pv]) continue;
                else if(vals[pu] == vals[pv]){
                    ans += sz[pu][vals[pu]] * sz[pv][vals[pv]];
                    sz[pu][vals[pu]] += sz[pv][vals[pv]];
                    p[pv] = pu;
                }else if(vals[pu] > vals[pv]){
                    p[pv] = pu;
                }
            }
        }
        return ans;
    }
};