//https://codeforces.com/contest/888/problem/C

#include <bits/stdc++.h>
using namespace std;

// 思路：26个字母的最大间距取最小值 边界处理

int main(){
    string s; cin>>s; s = "?" + s;
    int n = s.length() - 1; vector<int> pos[26];  
    for(int i=0;i<26;i++) pos[i].push_back(0);
    for(int i=1;i<=n;i++) pos[s[i]-'a'].push_back(i);
    for(int i=0;i<26;i++) pos[i].push_back(n+1);
    int ans = INT_MAX;
    for(int i=0;i<26;i++){
        int res = 0;
        for(int j=1;j<pos[i].size();j++){
            res = max(res, pos[i][j] - pos[i][j-1]);
        }
        ans = min(ans,res);
    }
    cout << ans << "\n";
    return 0;
}


/**
 * 二分写法 
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n;
string s;
int cnt[maxn][26];

bool check(int k){
    vector<int> sz(26);
    for(int l=1;l+k-1<=n;l++){
        int r = l + k - 1;
        for(int i=0;i<26;i++) {
            sz[i] += (cnt[r][i] - cnt[l-1][i]) > 0;
        }
    }
    bool suc = false;
    for(int i=0;i<26;i++) 
        if(sz[i] == n - k + 1)
            suc = true;
    return suc;
}

int main(){
    cin>>s; n = s.length(); s = "?" + s;
    for(int i=1;i<=n;i++) cnt[i][s[i]-'a'] += 1;
    for(int i=1;i<=n;i++) 
        for(int j=0;j<26;j++)
            cnt[i][j] += cnt[i-1][j];
    int l = 0 , r = n;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << "\n";
    return 0;
}

*/