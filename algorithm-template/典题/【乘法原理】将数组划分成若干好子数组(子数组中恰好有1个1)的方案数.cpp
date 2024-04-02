// 乘法原理
// 隔板法：在相邻的两个1之间插入一个隔板
class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        const int mod = 1e9 + 7;
        int n = nums.size(), pre = -1; // pre表示上一个1的位置
        int ans = 1;
        for(int i=0;i<n;i++) {
            if(nums[i] == 0) continue;
            if(pre != -1) ans = 1LL * ans * (i - pre) % mod;
            pre = i;
        }
        return (pre == -1 ? 0 : ans);
    }
};