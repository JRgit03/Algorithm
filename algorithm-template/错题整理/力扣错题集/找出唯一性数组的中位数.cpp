// 找出唯一性数组的中位数
// https://leetcode.cn/problems/find-the-median-of-the-uniqueness-array/
// 唯一性数组一共有 (1 + n) * n / 2 个, 中位数就是第(m + 2 - 1) / 2个数字 
// 二分答案, check: distinct值小于等于up的子数组的数量是否大于等于k
class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        typedef long long ll;
        ll n = nums.size(), m = (1 + n) * n / 2, k = (m + 2 - 1) / 2;
        auto check = [&](int up){
            ll cnt = 0, sz = 0;
            unordered_map<int, int> mp;
            for(int r=0,l=0;r<n;r++){
                if(++mp[nums[r]] == 1) sz += 1;
                while(l <= r && sz > up){
                    if(--mp[nums[l]] == 0) sz -= 1;
                    l += 1;
                }
                cnt += r - l + 1;
            }
            return cnt >= k;
        };
        int l = 1, r = set<int>(nums.begin(), nums.end()).size();
        while(l < r){
            int mid = (l + r) >> 1;
            if(check(mid)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};