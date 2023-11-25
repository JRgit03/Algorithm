// 前缀和 + 进制压缩
// 只考虑每个字符出现的奇偶性 并 优先考虑 每个前缀状态出现的首个位置
// 字符出现均为偶数次 + 枚举保留的奇数字符
// https://leetcode.cn/problems/find-longest-awesome-substring/description/
class Solution {
public:
    int longestAwesome(string s) {
        int n = s.length(), cur = 0;
        vector<int> f(1<<10,-1); f[0] = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            int x = s[i] - '0';
            cur ^= (1 << x);
            if(f[cur] != -1){
                ans = max(ans, i+1 - f[cur]);
            }else{
                f[cur] = i+1;
            }
            for(int j=0;j<10;j++){
                if(f[cur ^ (1 << j)] != -1){
                    ans = max(ans, i+1 - f[cur ^ (1 << j)]);
                }
            } 
        }
        return ans;
    }
};