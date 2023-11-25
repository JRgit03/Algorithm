class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pos;
        for(int i=0;i<n;i++) 
            if(nums[i] & 1)
                pos.push_back(i+1);
        int ans = 0;
        int l = 0, r = l + k - 1; //cout << l << " " << r << "\n";
        for(;r<pos.size();l++,r++){
            int lsz = (l > 0 ? pos[l] - pos[l-1] : pos[l]);
            int rsz = (r + 1 < pos.size() ? pos[r+1] - pos[r] : n+1-pos[r]);
            // cout << l << " " << r << " " <<  lsz << " " << rsz << "\n";
            ans += lsz * rsz;
        }
        return ans;
    }
};