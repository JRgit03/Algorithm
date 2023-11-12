/**
 * nums[j] <= nums[i] <= 2 * nums[j] (j <= i)  
 * 题意：对于每个区间[j~i]内最大异或对
 * 
 * 删除操作 并非直接删除而是作了标记cnt次数
 * https://leetcode.cn/contest/weekly-contest-371/problems/maximum-strong-pair-xor-ii/
 **/
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size();
        int maxn = 1e6 + 10, idx = 0;
        int son[maxn][2]; memset(son,0,sizeof son);
        int cnt[maxn]; memset(cnt,0,sizeof cnt);
        auto insert = [&](int x){
            int p = 0;
            for(int i=19;i>=0;i--){
                int u = (x >> i) & 1;
                if(!son[p][u]) son[p][u] = ++idx;
                p = son[p][u];
                cnt[p]++;
            }
        };
        auto remove = [&](int x){
            int p = 0;
            for(int i=19;i>=0;i--){
                int u = (x >> i) & 1;
                p = son[p][u];
                cnt[p]--;
            }
        };
        auto query = [&](int x){
            int p = 0,res = 0;
            for(int i=19;i>=0;i--){
                int u = (x >> i) & 1;
                if(cnt[son[p][!u]] > 0 && son[p][!u]){
                    res = res * 2 + !u;
                    p = son[p][!u];
                }else{
                    res = res * 2 + u;
                    p = son[p][u];
                }
            }
            return res;
        };
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i=0,j=0;i<n;i++){
            int tar = (nums[i] + 2 - 1) / 2;
            while(j < i && nums[j] < tar) remove(nums[j++]);
            insert(nums[i]); int t = query(nums[i]);
            // cout << j << " " << i << " " << t << " " << (t ^ nums[i]) << "\n";
            ans = max(ans, nums[i] ^ t);
        }
        return ans;
    }
};