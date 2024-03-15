/**
给你一个整数数组 nums 和一个 正整数 k 。你可以选择数组的任一 子序列 并且对其全部元素求和。
数组的 第 k 大和 定义为：可以获得的第k个最大子序列和（子序列和允许出现重复）
返回数组的 第 k 大和 。
*/
class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        typedef pair<long long, long long> PLL;
        int n = nums.size();
        long long sum = 0;
        for(int i=0;i<n;i++){
            if(nums[i] > 0) sum += nums[i];
            else nums[i] = -nums[i];
        }
        sort(nums.begin(), nums.end());
        priority_queue<PLL, vector<PLL>, greater<PLL> > heap;
        heap.push({0,0}); // [] 空子序列 {子序列之和, 下一个添加/替换的下标}
        while(--k){
            auto [s, i] = heap.top(); heap.pop();
            if(i < nums.size()){
                // 子序列末尾添加nums[i]
                heap.push({s + nums[i], i + 1}); // 下一个添加/替换的下标为i+1
                if(i - 1 >= 0){ // 子序列末尾替换为
                    heap.push({s + nums[i] - nums[i-1], i + 1});
                }        
            }
        }
        return sum - heap.top().first; 
    }
};

// 第k大子序列和 = 正数之和 - 第k小子序列和
// 结合最小堆，就可以按照从小到大的顺序生成所有子序列了（堆中维护子序列的和以及下一个要添加/替换的元素下标）。取生成的第 k 个子序列的和，
// 作为 sum 要减去的数

// 证明： 把子序列和它通过添加/替换生成的子序列之间连一条有向边，我们可以得到一棵以 [] 为根的有向树 出堆的元素和是非降的,类似dij