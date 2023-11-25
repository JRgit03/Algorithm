// 前缀和 + 进制压缩
// 只考虑每个字符出现的奇偶性 并 优先考虑 每个前缀状态出现的首个位置
// https://leetcode.cn/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/
class Solution {
public:
    int findTheLongestSubstring(string s) {
        string t = "aeiou";
        map<int,int> mp; 
        for(int i=0;i<5;i++) mp[t[i]] = i;
        int cur = 0; // u o i e a 进制压缩  00000 ~ 11111 每个字符出现的奇偶性 0 偶 1 奇
        vector<int> f(32,-1); f[0] = 0; // f[i] 表示 状态i最先出现的位置
        int n = s.length(), ans = 0; 
        for(int i=0;i<n;i++){
            char c = s[i];
            if(mp.count(c)) cur = cur ^ (1 << mp[c]);
            if(f[cur] == -1) f[cur] = i + 1;
            else ans = max(ans, i+1 - f[cur]);
        }    
        return ans;
    }
};