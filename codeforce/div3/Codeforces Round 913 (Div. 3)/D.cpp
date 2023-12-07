#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define dbug(x) cout << #x << '=' << x << endl
#define int long long
#define x first
#define y second
using namespace std;
const int N = 1e5 + 10, Mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
typedef pair<int,int> PII;
typedef long long ll;

void solve(){
    int n; cin>>n;
    vector<PII> vec(n); for(int i=0;i<n;i++) cin>>vec[i].first>>vec[i].second;
    auto merge = [&](PII p1, PII p2){
        auto [a,b] = p1;
        auto [c,d] = p2;
        PII res;
        if(c > b || d < a) res = {1,-1};
        else{
            if(c >= a && d <= b) res = {c,d};
            else if(c <= a && d >= b) res = {a,b};
            else if(d >= a && c <= a) res = {a,d};
            else if(c >= a && c <= b) res = {c,b};
            else res = {1,-1};
        }
        return res;
    };
    auto check = [&](int k){
        PII p = {0,0};
        for(int i=0;i<n;i++){
            p.first -= k,p.second += k;
            p = merge(p,vec[i]);
            // cout << p.first << " " << p.second << "\n";
            if(p.first > p.second) return false; 
        }
        return true;
    };
    // check(7);
    int l = 0, r = 1e9;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << "\n";
}

signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
