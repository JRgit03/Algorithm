//https://leetcode.cn/problems/minimum-number-of-operations-to-make-array-continuous/?envType=daily-question&envId=2024-04-08
/*
    使数组连续的最少操作次数
    题意：给定长度为n的数组，每次操作可替换任意元素为任意正数，求使数组连续的最少操作次数
    思路：正难则反, 原问题=> n - 最大可以保留多少个元素
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        // 对原数组排序并且去重
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()), nums.end());
        int q[n+10],hh,tt; 
        hh = 0, tt = -1;
        int m = nums.size();
        int ans = n;
        for(int i=0;i<m;i++){
            while(hh <= tt && nums[i] - nums[q[hh]] + 1 > n) hh += 1;
            q[++tt] = i;
            ans = min(ans, n - (tt - hh + 1));
        }
        return ans;
    }
};