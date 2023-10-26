#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define dbug(x) cout << #x << '=' << x << endl
#define int long long
#define x first
#define y second
#define ONLINE_JUDGE  
using namespace std;
const int N = 1e5 + 10, Mod = 998244353, INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
typedef long long ll;

int dp[220][11]; // dp[i,j] 前i位余数为j的神奇数个数
string s; int m;

// remain 余数
// dfs(i,rem,isLimit,isNum,last)
// 表示 前i个数 余数为rem isLimit是否受到限制 isNum当前枚举的数是否合法 last枚举的最后一位数字
// 本题需要枚举最后一位数字 dfs到前m-1位 直接判断
int dfs(int i,int rem,int isLimit,int isNum,int last){
    if(i == m - 1){
        if(!isNum) return 0;
        if(isLimit && last > s.back() - '0') return 0;
        return rem % last == 0; 
    }
    if(!isLimit && isNum && dp[i][rem] != -1) return dp[i][rem] % Mod;
    
    int res = 0;
    if(!isNum) res = dfs(i+1,rem,0,0,last);

    int up = isLimit ? s[i] - '0' : 9;
    for(int d=1-isNum;d<=up;d++){
        res = (res + dfs(i+1,(rem+d)%last,isLimit&(d==up),1,last)) % Mod;
    }

    if(!isLimit && isNum) dp[i][rem] = res;
    return res;
}

// 计算 1~x 神奇数
int solve(string x){
    s = x; 
    m = s.length();
    int ans = 0;
    for(int i=1;i<=9;i++){
        memset(dp,-1,sizeof dp);
        ans = (ans + dfs(0,0,1,0,i)) % Mod;
    }
    return ans;
}

int check(string x){
    int sum = 0 , last = x.back() - '0';
    for(auto c : x) sum += c - '0';
    sum -= last;
    return last != 0 && (sum % last == 0);
}

signed main(){
    IOS;
    string L,R; cin>>L>>R;
    cout << (solve(R) - solve(L) + check(L) + Mod) % Mod << "\n";
    return 0;
}
