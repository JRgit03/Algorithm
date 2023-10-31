#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define dbug(x) cout << #x << '=' << x << endl
#define int long long
#define x first
#define y second
#define ONLINE_JUDGE  
using namespace std;
const int N = 3e5 + 10, Mod = 998244353, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
typedef pair<int,int> PII;
typedef long long ll;
int n;
int a[N];
int dp[N]; // dp[i] 表示 当前投掷出的是i 继续到游戏结束的期望值

int fastpow(int a,int b){
    int res = 1;
    while(b){
        if(b & 1) res = res * a % Mod;
        b >>= 1;
        a = a * a % Mod;
    }
    return res;
}

int inv(int x){
    return fastpow(x,Mod-2);
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[n] = 0; int suf = dp[n] + a[n];
    for(int i=n-1;i>=0;i--){
        dp[i] = suf * inv(n) % Mod;
        suf = (suf + dp[i] + a[i]) % Mod;
    }
    cout << dp[0] << "\n";
}

signed main(){
    IOS; solve();
    return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////
/**
 * 赛时写出的dp
 * 考虑每个数对答案的贡献
 * dp[i] 表示 以 第i个数为终止点 的 期望概率
 * dp[i] = dp[i-1] / n + dp[i-1]
 */
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 10 , Mod = 998244353;
int n;
int a[N];
int dp[N];

int fastpow(int a,int b){
	int res = 1;
	while(b){
		if(b & 1) res = res * a % Mod;
		b >>= 1;
		a = a * a % Mod;
	}
	return res;
}

int inv(int x){
	return fastpow(x,Mod-2);
}

signed main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dp[1] = inv(n);
	for(int i=2;i<=n;i++) dp[i] = (dp[i-1] * inv(n) % Mod + dp[i-1] % Mod + Mod) % Mod;
	int ans = 0;
	for(int i=1;i<=n;i++) ans = (ans + dp[i] * a[i]) % Mod;
	cout << (ans + Mod) % Mod << "\n";
	return 0;
}