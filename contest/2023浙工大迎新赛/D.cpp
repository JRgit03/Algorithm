#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define dbug(x) cout << #x << '=' << x << endl
#define debug_(x) cerr << #x << " = " << (x) << ' '
#define debug(x) cerr << #x << " = " << (x) << '\n'
#define debugsq(x) cerr << #x << ": ["; for (auto i : x) cerr << i << ' '; cerr << "]\n";
#define debugmp(x) cerr << #x << ": [ "; for (auto [i, j] : x) cerr << '[' << i << "," << j << "] "; cerr << "]\n";
#define int long long
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 10, Mod = 1e9 + 7, INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1.0);
typedef pair<int,int> PII;
typedef long long ll;

int n,k;
int a[N],b[N],c[N];

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) c[i] = b[i] - a[i];
    if(k >= n){
        cout << 0 << "\n";
        return;
    }
    sort(c+1,c+1+n);
    int l = 1, r = n - k;
    int pre = 0, suf = 0;
    int mid = (l + r) >> 1;
    int lsz = mid - l, rsz = r - mid;
    for(int i=l;i<=r;i++){
        if(i < mid) pre += c[i];
        else if(i > mid) suf += c[i];
    }
    int ans = INF; 
    ans = min(ans, lsz * c[mid] - pre + suf - rsz * c[mid]);
    while(r >= 1 && r+1 <= n){
        pre -= c[l]; l++; pre += c[mid];
        suf -= c[++mid]; r++; suf += c[r];
        ans = min(ans, lsz * c[mid] - pre + suf - rsz * c[mid]);
    }
    cout << ans << "\n";
}

signed main(){
    IOS; solve();
    return 0;
}
