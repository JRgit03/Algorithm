// https://leetcode.cn/problems/maximum-profit-in-job-scheduling/description/
// 题意：给定n段[a,b,c]要求区间不重叠且sum(c)最大 经典dp问题！
// 二分 + dp
// dp[i] 表示 前i份工作可以获得的最大报酬
// 不选 dp[i] = dp[i-1];
// 选   dp[i] = dp[j] + v[i] (j<i, j是最后一个ed[j]<=st[i])
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size(); 
        int dp[n+1]; dp[0] = 0;
        vector<array<int,3>> vec(n+1);
        for(int i=1;i<=n;i++) vec[i] = {startTime[i-1],endTime[i-1], profit[i-1]};
        sort(vec.begin() + 1, vec.end(), [&](auto &p, auto &q){return p[1] < q[1];});
        for(int i=1;i<=n;i++){
            dp[i] = dp[i-1];
            int l = 0, r = i - 1; // 二分左边界为0!
            while(l < r){
                int mid = (l + r + 1) >> 1;
                if(vec[mid][1] <= vec[i][0]) l = mid;
                else r = mid - 1;
            }
            if(vec[r][1] <= vec[i][0]) dp[i] = max(dp[i], dp[r] + vec[i][2]);
        }
        return dp[n];
    };

};