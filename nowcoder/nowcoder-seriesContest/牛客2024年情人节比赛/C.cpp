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
const int N = 1e6 + 10, Mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
typedef pair<int,int> PII;
typedef long long ll;

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int primes[N], cnt;
int st[N];

set<int> s;

int f[N];

void init(){
    for(int i=2;i<=1000000;i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j=0;primes[j] <= 1000000 / i; j++){
            st[primes[j] * i] = 1;
            if(i % primes[j] == 0) break;
        } 
    } 
    // dbug(cnt); cnt=78498
    for(int i=0;i<cnt;i++) s.insert(primes[i]);
    for(int i=0;i<=1000000;i++) f[i] = f[i-1] + (s.count(i - 2) && s.count(i));
}
 
void solve(){
    int n; cin>>n;
    cout << f[n] << "\n";
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
