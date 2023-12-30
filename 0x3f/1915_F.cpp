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
const int N = 4e5 + 10, Mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double eps = 1e-8;
typedef pair<int,int> PII;
typedef long long ll;

vector<int> all;
int getPos(int x){
    int l = 0, r = all.size() - 1;
    return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
}

int tr[N];
int lowbit(int x){return x&-x;}
void add(int x,int c){for(int i=x;i<=all.size();i+=lowbit(i)) tr[i] += c;}
int sum(int x){int res = 0;for(int i=x;i;i-=lowbit(i)) res += tr[i];return res;}

void solve(){
    int n; cin>>n;
    vector<PII> vec(n); all.clear();
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        all.push_back(x); all.push_back(y);
        vec[i] = {x,y};
    }
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()), all.end());
    int m = all.size(); for(int i=1;i<=m;i++) tr[i] = 0;
    sort(vec.begin(), vec.end());
    int ans = 0; for(int i=n-1;i>=0;i--){
        int l = getPos(vec[i].first), r = getPos(vec[i].second);
        ans += sum(r); add(r, 1);
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
