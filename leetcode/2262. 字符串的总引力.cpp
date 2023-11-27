// https://leetcode.cn/problems/total-appeal-of-a-string/description/
// 计算每个字符的贡献
// 对于当前字符c的贡献为： l = pre[c] ~ cur[c], r = cur[c] ~ n 可以防止重复计算贡献 
class Solution {
public:
    long long appealSum(string s) {
        int n = s.length();
        vector<int> pre(26,-1);
        long long ans = 0;
        for(int i=0;i<n;i++){
            ans += 1LL * (i - pre[s[i] - 'a']) * (n - i);
            pre[s[i]-'a'] = i;
        }
        return ans;
    }
};
// class Solution {
// public:
//     long long appealSum(string s) {
//         int n = s.length(); s = "?" + s;
//         vector<int> pos[26];
//         for(int i=1;i<=n;i++) pos[s[i]-'a'].push_back(i);
//         long long ans = 0;
//         for(int i=0;i<26;i++){
//             for(int j=0;j<pos[i].size();j++){
//                 int l = (j == 0 ? pos[i][j] : pos[i][j] - pos[i][j-1]);
//                 int r = n - pos[i][j] + 1;
//                 ans += 1LL * l * r;
//             }
//         }
//         return ans;
//     }
// };