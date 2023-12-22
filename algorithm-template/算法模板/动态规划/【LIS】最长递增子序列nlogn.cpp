#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> g; // 最长递增子序列
vector<int> f; // 以nums[i]结尾的最长递增子序列长度

void LIS(vector<int> &nums){
    for (int x : nums) {
        auto it = lower_bound(g.begin(), g.end(), x);
        f.push_back(it - g.begin() + 1);
        if (it == g.end()) g.push_back(x); // >=x 的 g[j] 不存在
        else *it = x;
    }
    return g; // 返回最长递增子序列
}

int main(){
    cin>>n;
    vector<int> nums(n); for(auto &x : nums) cin>>x;
    LIS(nums); cout << g.size() << "\n";
    return 0;
}
