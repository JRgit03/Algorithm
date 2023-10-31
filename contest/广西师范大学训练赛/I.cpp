#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define dbug(x) cout << #x << '=' << x << endl
#define int long long
#define x first
#define y second
#define ONLINE_JUDGE  
using namespace std;
const int N = 2e5 + 10, Mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
typedef pair<int,int> PII;
typedef long long ll;

void solve(){
    int n,k; cin>>n>>k;
    vector<int> a(n); for(auto &x : a) cin>>x;
    int f = 0;
    for(int i=0;i<n;i++){
        int j=i+1;
        while(j<n && a[j] >= a[j-1]) j++;
        f |= (j - i>= k);
        i = j - 1;
    }
    if(!f) sort(a.begin() + n - k , a.end());
    for(auto x : a) cout << x << " ";
}

signed main(){
    IOS; solve();
    return 0;
}
