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
const int N = 2e5 + 10, mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
typedef pair<int,int> PII;
typedef long long ll;

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int pre[N]; // pre[i] 对于第i位 右边第一位1的位置
int suf[N]; // suf[i] 对于第i位 左边第一位0的位置

// 对于 一个区间排序[l,r]操作,  区间左的0/右边的1 对区间修改没有意义
void solve(){
    int n,m; cin>>n>>m;
    string s; cin>>s; s = "?" + s;
    int pos = 0;
    for(int i=1;i<=n;i++) {
        if(s[i] == '0') pos = i;
        suf[i] = pos;
    }
    pos = n + 1;
    for(int i=n;i>=1;i--) {
        if(s[i] == '1') pos = i;
        pre[i] = pos;
    }
    set<PII> st;
    while(m--){
        int l,r; cin>>l>>r;
        l = pre[l];
        r = suf[r];
        if(l >= r) st.insert({-1,-1});
        else st.insert({l,r}); 
    }
    cout << st.size() << "\n";
}

signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}

