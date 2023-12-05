// https://leetcode.cn/problems/minimum-replacements-to-sort-the-array/
// 构造非严格递增的数组
// 贪心：最后一个数显然不需要拆分,并且从后往前更优
// x：切割份数 minn：i~n 的 最小值
// 对于 nums[i] = v1 + v2 + ... + vx <= minn * x
// =>   x >= nums[i] / minn
// 要使得 x 尽可能小 x = (nums[i] + minn - 1) / minn 
class Solution {    
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size(), minn = nums.back();
        for(int i=n-2;~i;i--){
            if(nums[i] <= minn) minn = nums[i];
            else{
                int cnt = (nums[i] + minn - 1) / minn;
                ans += cnt - 1;
                minn = nums[i] / cnt;
            }
        }
        return ans;
    }
};