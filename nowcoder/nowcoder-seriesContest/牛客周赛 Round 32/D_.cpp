#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; cin>>s;
    int n = s.length();
    long long ans = 0, sum = 0;
    map<int,int> mp; mp[0] = 1;
    for(auto &c : s){
        sum ^= (1 << (c - '0'));
        ans += mp[sum];
        for(int i=0;i<10;i++) ans += mp[sum ^ (1 << i)];
        mp[sum] += 1;
    }
    cout << ans << "\n";
    return 0;
}
