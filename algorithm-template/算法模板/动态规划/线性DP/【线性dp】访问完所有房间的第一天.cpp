/*
题意：
你需要访问 n 个房间，房间从 0 到 n - 1 编号。同时，每一天都有一个日期编号，从 0 开始，依天数递增。你每天都会访问一个房间。
最开始的第 0 天，你访问 0 号房间。给你一个长度为 n 且 下标从 0 开始 的数组 nextVisit 。
访问的规则：
1.假设某一天，你访问 i 号房间。
2.如果算上本次访问，访问 i 号房间的次数为 奇数 ，那么 第二天 需要访问 nextVisit[i] 所指定的房间，其中 0 <= nextVisit[i] <= i 。
3.如果算上本次访问，访问 i 号房间的次数为 偶数 ，那么 第二天 需要访问 (i + 1) mod n 号房间。
    请返回你访问完所有房间的第一天的日期编号。题目数据保证总是存在这样的一天。由于答案可能很大，返回对 1e9 + 7 取余后的结果。
*/
class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        const int mod = 1e9 + 7;
        int n = nextVisit.size(); 
        // dp[i] 表示 第一次访问到第i个房间的日期
        long long dp[n + 1]; memset(dp, 0, sizeof dp);
        for(int i=1;i<=n-1;i++){
            // 1. dp[i - 1] + 1 第一次访问第i-1个房间的日期 后一天
            // 2. 后一天将回退值前面的nextVisit[i - 1] 需要重新访问 dp[i - 1] - dp[nextVisit[i - 1]]
            // 3. + 1 第二次访问到第i-1个房间的日期 + 1 即是 一次访问到第i个房间的日期
            // 显然访问到第i个房间 前面的房间必定被访问了偶数次
            dp[i] = (dp[i - 1] + 1 + dp[i - 1] - dp[nextVisit[i - 1]] + 1 + mod) % mod;
        }
        return dp[n - 1];
    }
};