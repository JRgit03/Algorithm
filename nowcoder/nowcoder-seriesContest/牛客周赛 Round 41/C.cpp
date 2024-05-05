#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define SETPRECISION cout << fixed << setprecision(10);
#define int long long
using namespace std;

#ifdef LOCAL
#include "../../../algorithm-template/debug.h"
#else
#define debug(...) 21
#endif

const int N = 1e5 + 10, mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
typedef pair<int,int> PII;
typedef long long ll;

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

void solve(){
    int x = 0; while(x <= 1000) x += 4, debug(x);
    string s; cin>>s;
    int n = s.length(); 
    if(s.length() == 1) {
        cout << (stoi(s) % 4 == 0 ? 0 : -1) << "\n";
        return;
    }
    s = s + s;
    int k = 0, i = n - 2; while(k < n) {
        int x = (s[i] - '0') * 10 + s[i + 1] - '0';
        if(x % 4 == 0) {
            cout << k << "\n";
            return;
        }
        k += 1, i += 1;
    }
    cout << -1 << "\n";
    return;
}

signed main(){
    IOS;
    int T=1;
    // cin>>T;
    while(T--)
        solve();
    return 0;
}
