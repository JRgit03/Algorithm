#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,l,r;
string s;
 
// 差分 + 双指针 -> 计数
// 至多k种字母的方案数
int calc(int k){
    if(!k) return 0;
    vector<int> cnt(26,0);
    int ans = 0 , sz = 0;
    int l=0,r=0;
    for(;r<n;r++){ //枚举右端点 保证不重复计算
        if(++cnt[s[r] - 'a'] == 1) sz++;
        while(l<r && sz > k){
            if(--cnt[s[l++] - 'a'] == 0) sz--;
        }
        ans += r - l + 1;
    }
    return ans;
}

signed main(){
    cin>>n>>l>>r>>s;
    cout << calc(r) - calc(l-1) << "\n";
    return 0;
}
