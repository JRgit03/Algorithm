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

void solve(){
    int n,k; cin>>n>>k;
    vector<int> a(n); for(auto &x : a) cin>>x;
    int ans = 0;
    int l = 0, r = n - 1; 
    while(k > 0 && l <= r){
        if(l == r){
            if(k - a[r] >= 0) ans++;
            break;
        }
        int minx = min(a[l], a[r]);
        if(k - 2 * minx >= 0){
            a[l] -= minx;
            a[r] -= minx;
            k -= 2 * minx;
            if(a[l] == 0 && a[r] == 0){
                ans += 2, l++, r--;
            }else if(a[l] == 0){
                ans += 1, l++;
            }else{
                ans += 1, r--;
            }
        }else{
            a[l] -= k / 2;
            if(k & 1) a[l] -= 1;
            if(a[l] == 0) ans++;
            break;
        }
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
