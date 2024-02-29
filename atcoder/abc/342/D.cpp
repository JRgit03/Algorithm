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
    int n; cin>>n;
    map<int,int> cnt; int sz0 = 0; // sz0 纯0的数量
    int ans = 0;
    for(int j = 0; j < n; j++){
        int x; cin>>x;
        if(x == 0){
            ans += j;
            sz0 += 1;
            continue;
        }
        vector<int> vec;
        for(int i=2;i<=x/i;i++){
            if(x % i == 0){
                int s = 0;
                while(x % i == 0) x /= i, s += 1;
                if(s & 1) vec.push_back(i);
            }
        } if(x > 1) vec.push_back(x);
        int mul = (vec.size() == 0 ? 0 : 1);
        for(auto v : vec) mul *= v;
        ans += cnt[mul] + sz0;
        cnt[mul] += 1;
    }
    cout << ans << "\n";
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
