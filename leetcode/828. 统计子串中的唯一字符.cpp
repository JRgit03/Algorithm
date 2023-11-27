// https://leetcode.cn/problems/count-unique-characters-of-all-substrings-of-a-given-string/?envType=daily-question&envId=2023-11-26
class Solution {
public:
    int uniqueLetterString(string s) {
        vector<int> vec[26];
        int n = s.length(); s = "?" + s;
        for(int i=1;i<=n;i++) vec[s[i]-'A'].push_back(i);
        int ans = 0;
        for(int i=0;i<26;i++){
            for(int j=0;j<vec[i].size();j++){
                int k = vec[i][j];
                int l = (j == 0 ? 0 : vec[i][j-1]), r = (j == vec[i].size() - 1 ? n+1 : vec[i][j+1]);
                ans += (k - l) * (r - k);
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     int uniqueLetterString(string s) {
//         vector<int> vec[26];
//         for(int i=0;i<26;i++) vec[i].push_back(0);
//         int n = s.length(); s = "?" + s;
//         for(int i=1;i<=n;i++) vec[s[i]-'A'].push_back(i);
//         for(int i=0;i<26;i++) vec[i].push_back(n+1);
//         auto findl = [&](int c,int k){ //第一个小于 s[k]
//             int l = 0, r = vec[c].size() - 1;
//             while(l < r){
//                 int mid = l + r + 1 >> 1;
//                 if(vec[c][mid] < k) l = mid;
//                 else r = mid - 1;
//             }
//             return vec[c][r];
//         };
//         auto findr = [&](int c,int k){ //第一个大于 s[k]
//             int l = 0, r = vec[c].size() - 1;
//             while(l < r){
//                 int mid = l + r >> 1;
//                 if(vec[c][mid] > k) r = mid;
//                 else l = mid + 1;
//             }
//             return vec[c][r];
//         };
//         int ans = 0;
//         for(int i=1;i<=n;i++){
//             int l = findl(s[i]-'A',i), r = findr(s[i]-'A',i);
//             //cout << i << " " << l << " " << r << "\n";
//             ans += (i - l) * (r - i);
//         }
//         return ans;
//     }
// };