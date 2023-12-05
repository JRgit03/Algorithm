#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    const int mod = 1e9 + 7;
    int n; cin>>n;
    vector<int> w(n+1);
    for(int i=1;i<=n;i++) cin>>w[i];
    vector<vector<int>> cnt(55,vector<int>(26,0)); // cnt[i][j] 表示长度为i首字母为j的出现次数
    int m; cin>>m; 
    vector<string> s(m+1); 
    for(int i=1;i<=m;i++) cin>>s[i], cnt[s[i].length()][s[i][0]-'a'] += 1;
    // hidden message 长度显然为n 计算长度为n作为目标子串的贡献
    int ans = 0;
    for(int i=1;i<=m;i++){
        if(s[i].length() == n){
            cnt[s[i].length()][s[i][0]-'a'] -= 1; //除去自身
            int res = 1;
            for(int j=1;j<=n;j++){
                int ne = s[i][j-1]-'a';
                res = (res * cnt[w[j]][ne]) % mod;
                cnt[w[j]][ne]--;
            }
            ans = (ans + res) % mod;
            cnt[s[i].length()][s[i][0]-'a'] += 1;
            for(int j=1;j<=n;j++){
                int ne = s[i][j-1]-'a';
                cnt[w[j]][ne]++;
            }
        }
    }
    cout << ans << "\n";
}

signed main(){
    int t; cin>>t;
    while(t--)  
        solve();
    return 0;
}
