#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define SETPRECISION cout << fixed << setprecision(10);
#define dbug(x) cout << #x << '=' << x << endl
#define debug_(x) cerr << #x << " = " << (x) << ' '
#define debug(x) cerr << #x << " = " << (x) << '\n'
#define debugsq(x) cerr << #x << ": ["; for (auto i : x) cerr << i << ' '; cerr << "]\n";
#define debugmp(x) cerr << #x << ": [ "; for (auto [i, j] : x) cerr << '[' << i << "," << j << "] "; cerr << "]\n";
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 10, Mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
typedef pair<int,int> PII;
typedef long long ll;

// 贪心
// 特殊考虑当ti=0时 答案显然是 最左点 + 最右点 的 中点
// 一般化 => 将一个人视为两个t=0的人 xi - ti & xi + ti
void solve1(){
    int n; cin>>n;
    vector<int> t(n),x(n);
    for(auto &v : x) cin>>v;
    for(auto &v : t) cin>>v;
    int L = INF, R = -INF;
    for(int i=0;i<n;i++){
        L = min(L, x[i] - t[i]);
        R = max(R, x[i] + t[i]);
    } 
    cout << (R + L) / 2.0 << "\n";
}

// 二分最大时间
// 对于所有的 ti + |xi - pos| <= t  等价于 - (t - ti) + xi <= pos <= t - ti + xi 所有区间有交集
void solve2(){
    int n; cin>>n;
    vector<int> t(n),x(n);
    for(auto &v : x) cin>>v;
    for(auto &v : t) cin>>v;
    double ans; // 记录位置
    auto check = [&](double k){
        double l = 0, r = 2e8;
        for(int i=0;i<n;i++){
            if(t[i] >= k) return false;
            l = max(l, - (k - t[i]) + x[i]);
            r = min(r, k - t[i] + x[i]);
        } 
        ans = r; //记录最后二分的合法位置
        return r - l >= eps;
    };
    double l = 0, r = 2e8;
    for(int i=0;i<100;i++){ // for 控制次数
        double mid = (l + r) / 2.0;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    SETPRECISION;
    int T=1; 
    cin>>T;
    while(T--){
        if(rand() % 2) solve1();
        else solve2();
    }
    return 0;
}
