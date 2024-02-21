#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define SETPRECISION cout << fixed << setprecision(10);
#define debug(x) cerr << #x << " = " << (x) << '\n'
#define debugsq(x) cerr << #x << ": ["; for (auto i : x) cerr << i << ' '; cerr << "]\n";
#define debugmp(x) cerr << #x << ": [ "; for (auto [i, j] : x) cerr << '[' << i << "," << j << "] "; cerr << "]\n";
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 4e5 + 10, mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
typedef pair<int,int> PII;
typedef long long ll;

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

void init(){
    
}

int a[N];
int b[N];

void add(int l,int r,int c){
    b[l] += c, b[r+1] -= c; 
}

// 从 0 ~ 目标数字 共有多少位变化 99 -> 100 变化三位
// 42 = 40 + 2
// 0 ~ 40 = 40 
// f[i] 表示 1 ~ 10^i 次 需要 的 步数 
// 显然 f[i] = 111....111   i个1的步数 
void solve(){
    int n; cin>>n;
    for(int i=1;i<=n;i++) a[i] = b[i] = 0;
    string s; cin>>s; 
    reverse(s.begin(), s.end()); s = "@" + s;
    for(int i=1;i<=n;i++) {
        add(1,i,s[i]-'0'); //debug(s[i]-'0');
    }
    for(int i=1;i<=n;i++) a[i] = a[i-1] + b[i];
    int c = 0;
    for(int i=1;i<=n;i++){
        int t = a[i] + c; //debug(t);
        a[i] = t % 10; //debug(a[i]);
        c = t / 10; //debug(c);
    }
    if(c > 0) a[++n] = c; 
    while(n >= 2 && !a[n]) n--; //debug(n);
    for(int i=n;i>=1;i--) cout << a[i]; cout << "\n";
}

signed main(){
    IOS;
    init();
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
