#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 10 , P = 1e9 + 7;
int n;
string str;
typedef unsigned long long ULL;
ULL h[N],p[N];

ULL gethash(int l,int r){
    return h[r] - h[l-1] * p[r-l+1];
}

// 最短唯一子串
// 如果最短唯一子串长度为k 则 在子串前后+1 仍是唯一子串
void solve(){
    cin>>str;
    n = str.length();
    p[0] = 1;
    for(int i=1;i<=n;i++){
        h[i] = h[i-1] * P + str[i - 1];
        p[i] = p[i-1] * P;
    }
    // 判断长度为k的字符串中是否存在唯一子串
    auto check = [&](int len){
        map<ULL, int> mp;
        for(int l=1;l+len-1<=n;l++){
            int r = l + len - 1;
            mp[gethash(l,r)] += 1;
        }
        int suc = 0;
        for(auto [h, sz] : mp) suc |= (sz == 1);
        return suc;
    };
    int l = 1, r = n;
    while(l < r){
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    } 
    map<ULL, int> mp;
    int len = r;
    for(int l=1;l+len-1<=n;l++){
        int r = l + len - 1;
        mp[gethash(l,r)] += 1;
    }
    for(int l=1;l+len-1<=n;l++){
        int r = l + len - 1;
        if(mp[gethash(l,r)] == 1){
            cout << str.substr(l-1, len) << "\n";
            return;
        } 
    }
}

signed main(){
    solve();
    return 0;
}
