#include <bits/stdc++.h>
using namespace std;
using i64 = unsigned long long;

const int N = 5e5 + 10;
const int mod = 998244353;
const int base = 131;
i64 h1[N],h2[N];
i64 p[N];
string s;
bool solve(string s) {
	int n = s.size();
	s = " " + s;
	int pos = -1;
	for (int i = 1; i <= n / 2; i ++) {
		if (s[i] != s[n - i + 1]) {
			pos = i;
			break;
		}
	}
	if (pos == -1) {
		return 1;
	}
	p[0] = 1;
	h1[0] = 0;
	h2[n + 1] = 0;
	for (int i = 1,j = n; i <= n; i ++,j --) {
		p[i] = p[i - 1] * base % mod;
		h1[i] = (h1[i - 1] * base % mod + (s[i] - 'a' + 1)) % mod;
		h2[j] = (h2[j + 1] * base % mod + (s[j] - 'a' + 1)) % mod;
	}
	auto get1 = [&](int l,int r) -> i64 {
		return (h1[r] - h1[l - 1] * p[r - l + 1] % mod + mod) % mod;
	};
	auto get2 = [&](int l,int r) -> i64 {
		return (h2[l] - h2[r + 1] * p[r - l + 1] % mod + mod) % mod;
	};
	auto check = [&](int l,int r,int len) -> int {
		i64 hash1 = (h1[len] - get1(l,r) * p[len - r] % mod + get2(l,r) * p[len - r] % mod + mod) % mod;
		i64 hash2 = (h2[1] - get2(l,r) * p[l - 1] % mod + get1(l,r) * p[l - 1] % mod + mod) % mod;
		return hash1 == hash2;
	};
    for (int i = pos; i <= n - pos + 1; i ++) {
        if (check(pos,i,n) || check(i, n - pos + 1, n)) {
            return 1;
        }
    }
	return 0;
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1; cin >> t;

	while (t --) {
		cin >> s;
		if (solve(s)) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
	return 0;
}