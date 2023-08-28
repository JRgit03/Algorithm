#include <bits/stdc++.h>
using namespace std;

vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
    typedef long long ll;
    int n = nums.size() , m = queries.size(); ll pre = 0 , suf = accumulate(nums.begin(),nums.end(),0L);
    sort(nums.begin(),nums.end());
    vector<int> id(m); iota(id.begin(),id.end(),0); sort(id.begin(),id.end(),[&](const int i,const int j){
        return queries[i] < queries[j];
    });
    vector<ll> ans(m); int k = 0;
    for(int i=0;i<n;i++){
        while(k<m && nums[i] >= queries[id[k]]) {
            ans[id[k]] = 1LL * i * queries[id[k]] - pre + suf - 1LL * (n - i) * queries[id[k]]; k++;
        }
        pre += nums[i] , suf -= nums[i];

    } 
    while(k<m) ans[id[k]] = n * queries[id[k]] - pre, k++;
    return ans;
}

int main()
{
    vector<int> nums = {58,5,26,89,15,48,13,1,29,3,46,64,70,63,47,43,74,24,19,55,15,89,91,8,51,3}; 
    vector<int> queries = {1,50,48,3,89,15,34,64,61,8,47,3,47,14,89,46,3,1,5,15,58,20,89,87,81,7,51,64,40,51,63,3,52,58,46,19,3,15,20,69,63,56,47,29,49,56,12,29,40,10,15,49,49,7,55,46,54,75,47,18,57,63,63,1,89,26,47,4,48,63,69,46,1,27,48,1,56,27,32,3,51,47,1,15,79,38,21,1,46,79,1,89};
    auto res = minOperations(nums,queries);
    for(auto &x : res) cout << x << " ";
    return 0;
}
