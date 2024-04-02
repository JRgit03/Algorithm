/*
    给你一个整数数组 nums ，返回 nums 中所有 等差子序列 的数目。
    nums.size() <= 1000
*/
class Solution {
public:
    // O(n^2logn)
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        // dp[i,j] 表示以第i个数为结尾且公差为j的合法等差子序列
        // dp[i][d] += dp[j][d] (j < i && d = nums[i] - nums[j])
        map<long long,int> dp[n]; 
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                long long d = 1LL * nums[i] - nums[j];
                ans += dp[j][d];
                dp[i][d] += dp[j][d] + 1;
            }
        }
        return  ans;
    }
};