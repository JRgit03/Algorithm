#include <bits/stdc++.h>

#define int long long

const int N = 1e5 + 10, INF = 1e18, MOD = 998244353;

int n, m;
std::string s;
int dp[3][700], mp[N];

int get() {
	int pre = 1;
	for(int i = 0; i <= 1; i ++ ) {
		for(int j = 'a'; j <= 'z'; j ++ ) dp[i & 1][j] = 0;
		for(int j = 'A'; j <= 'Z'; j ++ ) dp[i & 1][j] = 0;
		for(int j = '0'; j <= '9'; j ++ ) dp[i & 1][j] = 0;
	}
	
	for(int i = 1; i <= n; i ++ ) {
		for(int j = 'a'; j <= 'z'; j ++ ) dp[i & 1][j] = 0;
		for(int j = 'A'; j <= 'Z'; j ++ ) dp[i & 1][j] = 0;
		for(int j = '0'; j <= '9'; j ++ ) dp[i & 1][j] = 0;
		if(s[i] == '?') {
			for(int j = 'a'; j <= 'z'; j ++ ) {
				if(mp[j]) break;
				dp[i & 1][j] = ((pre - dp[i - 1 & 1][j]) % MOD + MOD) % MOD;
			}
			for(int j = 'A'; j <= 'Z'; j ++ ) {
				if(mp[j]) break;
				dp[i & 1][j] = ((pre - dp[i - 1 & 1][j]) % MOD + MOD) % MOD;
			}
			for(int j = '0'; j <= '9'; j ++ ) {
				if(mp[j]) break;
				dp[i & 1][j] = ((pre - dp[i - 1 & 1][j]) % MOD + MOD) % MOD;
			}
		}
		else if((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z')) {
			if(mp[s[i]]) return 0;
			dp[i & 1][s[i]] = pre - dp[i - 1 & 1][s[i]]; dp[i & 1][s[i]] = (dp[i & 1][s[i]] % MOD + MOD) % MOD;
		}
		else {
			int fl = 0;
			if(!mp[s[i]]) dp[i & 1][s[i]] = pre - dp[i - 1 & 1][s[i]], fl = 1;
			if(!mp[s[i] - 32]) dp[i & 1][s[i] - 32] = pre - dp[i - 1 & 1][s[i] - 32], fl = 1;
			if(!fl) return 0;
			dp[i & 1][s[i]] = (dp[i & 1][s[i]] % MOD + MOD) % MOD;
			dp[i & 1][s[i] - 32] = (dp[i & 1][s[i] - 32] % MOD + MOD) % MOD;
		}
		pre = 0;
		
		for(int j = 'a'; j <= 'z'; j ++ ) pre += dp[i & 1][j], pre %= MOD;
		for(int j = 'A'; j <= 'Z'; j ++ ) pre += dp[i & 1][j], pre %= MOD;
		for(int j = '0'; j <= '9'; j ++ ) pre += dp[i & 1][j], pre %= MOD;
	}
	return pre;
}

void add(int l, int r) {
	for(int i = l; i <= r; i ++ ) mp[i] = 1;
}

void clear(int l, int r) {
	for(int i = l; i <= r; i ++ ) mp[i] = 0;
}

void solve() {
	std::cin >> n >> s; s = '?' + s;
	
	int _a = 0, _A = 0, _0 = 0;
	int _aA = 0, _a0 = 0, _A0 = 0;
	int sum = get();
	add('a', 'z'); _a = get(); clear('a', 'z');
	add('A', 'Z'); _A = get(); clear('A', 'Z');
	add('0', '9'); _0 = get(); clear('0', '9');
	add('a', 'z'), add('A', 'Z'); _aA = get(); clear('a', 'z'), clear('A', 'Z');
	add('a', 'z'), add('0', '9'); _a0 = get(); clear('a', 'z'), clear('0', '9');
	add('A', 'Z'), add('0', '9'); _A0 = get(); clear('A', 'Z'), clear('0', '9');
	std::cout << ((sum - _a - _A - _0 + _aA + _a0 + _A0) % MOD + MOD) % MOD  << "\n";
}

signed main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int t = 1; 
	while(t -- ) solve(); return 0;
} 