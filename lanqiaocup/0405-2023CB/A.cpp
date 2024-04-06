#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
#define int long long
using namespace std;

void solve(){
    string s = "5686916124 9198236477 5950387581 5861830379 2705885709 9194468633 8516346707 8276895656 1401009480 9128502533";
    map<char,vector<int>> mp;
    for(int i=0;i<s.length();i++) mp[s[i]].push_back(i+1);
    int y = 2023, m = 1, d = 0;
    set<int> st = {1,3,5,7,8,10,12};
    int ans = 0;
    while(1){
        d += 1;
        int dd = (m == 2 ? 28 : 30 + st.count(m));
        if(dd + 1 == d){
            d = 1;
            m += 1;
            if(m == 13) break;
        }
        string t = to_string(y);    
        if(m < 10) t += "0" + to_string(m);
        else t += to_string(m);
        if(d < 10) t += "0" + to_string(d);
        else t += to_string(d);
        
        int pre = 0;
        for(auto c : t){
            int x = pre, y = s.length() - 1;
            int l = 0, r = mp[c].size() - 1;
            while(l < r){
                int mid = l + r >> 1;
                if(mp[c][mid] >= x && mp[c][mid] <= y) r = mid;
                else l = mid + 1;
            }
            if(mp[c][r] >= x && mp[c][r] <= y) pre = mp[c][r] + 1; // 当前合法的下一个
            else pre = s.length() + 1;
        }

        ans += (pre <= s.length()); // 235
    }
    cout << ans << "\n";
}

signed main(){
    IOS; solve();
    return 0;
}

// oj
// https://www.dotcpp.com/oj/train/1089/

// pdf
// https://www.lanqiao.cn/courses/2786/learning/?id=1116267&compatibility=false
