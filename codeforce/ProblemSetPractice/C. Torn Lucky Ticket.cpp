#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 10;
int n;
int a[maxn];
int dp[10][100]; // dp[i,j] 长度为i和为j的个数 si + sj 成立 不一定 sj + si 成立

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,[&](auto i,auto j){ // 保证分割点的位置
        return to_string(i).length() < to_string(j).length();
    });
    int ans = 0;
    for(int i=1;i<=n;i++) {
        string str = to_string(a[i]);
        int m = str.length();
        vector<int> s(m+1,0);
        for(int j=1;j<=m;j++) s[j] = s[j-1] + (str[j-1] - '0'); 
        // si + sj 
        for(int j=1;j<=m;j++){
            int pre = s[j], suf = s[m] - s[j];
            for(int k=1;k<=5;k++)
                if(k + j == m - j){
                    ans += dp[k][max(0LL,suf-pre)];  
                }      
        }
        ans += dp[m][s[m]];
        // sj + si
        for(int j=m;j>=1;j--){
            int pre = s[j], suf = s[m] - s[j];
            for(int k=1;k<=5;k++)   
                if(j == m - j + k){
                    ans += dp[k][max(0LL,pre-suf)];  
                }      
        }
        ans++;
        dp[m][s[m]] += 1;
    }
    cout << ans << "\n";
    return 0;
}
