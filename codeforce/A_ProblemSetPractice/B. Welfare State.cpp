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
const int N = 1e5 + 10, mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
typedef pair<int,int> PII;
typedef long long ll;

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

void init(){
    
}

void solve(){
    int n,m; cin>>n;
    vector<int> a(n+1); 
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>m;
    vector<int> last(n+1);
    vector<int> sufMax(m+1); // sufMax[i] 时间戳i~m的操作2 最大值
    for(int i=1;i<=m;i++){
        int op,p,x; cin>>op;
        if(op == 1){
            cin>>p>>x;
            last[p] = i;
            a[p] = x;
        }else if(op == 2){
            cin>>x;
            sufMax[i] = x;
        }
    }
    for(int i=m-1;i>=0;i--) sufMax[i] = max(sufMax[i], sufMax[i+1]);
    for(int i=1;i<=n;i++) a[i] = max(a[i], sufMax[last[i]]);
    for(int i=1;i<=n;i++) cout << a[i] << " ";
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

// a[i]的终值
// 对下标为i的 受最后一次操作1的影响
// 对下标为i的最后一次操作1之后的时间戳后的操作2 到 最后一次操作二 的 最大值
