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
const int N = 1e6 + 10, mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
typedef pair<int,int> PII;
typedef long long ll;

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

void init(){
    
}

int n,m;
int b[N];
int r[N];
array<int,3> op[N];

void add(int l,int r,int c){
    b[l] += c; b[r+1] -= c; 
}

// 1~k的操作是否合法
int check(int k){
    for(int i=1;i<=n;i++) b[i] = 0;
    for(int i=1;i<=k;i++) add(op[i][1], op[i][2], op[i][0]);
    int suc = 1;
    for(int i=1;i<=n;i++) {
        b[i] += b[i-1];
        if(b[i] > r[i]) suc = 0;
    }
    return suc;
}

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>r[i];
    for(int i=1;i<=m;i++)   
        for(int j=0;j<3;j++) 
            cin>>op[i][j];
    int l = 0, r = m;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    if(check(r) && r == m) cout << 0 << "\n";
    else cout << -1 << "\n" << r + 1 << "\n"; 
}

signed main(){
    IOS;
    init();
    int T=1;
    // cin>>T;
    while(T--)
        solve();
    return 0;
}


// 二分性质
// 显然对于第一个不符合的订单号，那么后续所有订单都是不符合的！
// 二分答案
// 使用差分加快区间加的速度