/**
 * https://atcoder.jp/contests/abc221/tasks/abc221_c
 */
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s; int n = s.length() , ans = 0;
    sort(s.begin(),s.end());
    do{
        for(int d=1;d<n;d++){ // 枚举分割点 
            int res1 = 0 , res2 = 0;
            for(int i=0;i<d;i++) res1 = res1 * 10 + s[i] - '0';
            for(int i=d;i<n;i++) res2 = res2 * 10 + s[i] - '0';
            ans = max(ans, res1 * res2);
        }
    } while (next_permutation(s.begin(),s.end())); // O(9! * 9^2 = 29393280 = 3e7)
    cout << ans << "\n";
    return 0;
}

// 贪心做法
//
// int main(){ 
//     string s; cin>>s;
//     priority_queue<char> heap;
//     for(auto c : s) heap.push(c);
//     string s1 = "", s2 = "";
//     while(heap.size()){
//         auto t = heap.top(); heap.pop();
//         if(!s1.length() || !s2.length()){
//             if(!s1.length()) s1 += t;
//             else s2 += t;       
//         }else if(s1.length() > 0 && s2.length() > 0){
//             if(stoi(s1 + t) * stoi(s2) >= stoi(s1) * stoi(s2 + t)) s1 += t;
//             else s2 += t;
//         }
//     }
//     cout << stoi(s1) * stoi(s2) << "\n";
//     return 0;
// }
