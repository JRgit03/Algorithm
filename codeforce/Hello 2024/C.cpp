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

void solve(){
    int n; cin>>n;
    vector<int> vec(n); for(auto &x : vec) cin>>x;  
    vector<int> v1,v2;
    int ans = 0;
    for(auto &x : vec){
        if(!v1.size()) v1.push_back(x);
        else if(!v2.size() && x <= v1.back()) v1.push_back(x);
        else if(!v2.size()) v2.push_back(x);
        else if(x <= v1.back() && x <= v2.back()){
            if(v1.back() <= v2.back()){
                v1.push_back(x);
            }else{
                v2.push_back(x);
            }
        } else if(x <= v1.back()) v1.push_back(x);
        else if(x <= v2.back()) v2.push_back(x);
        else {
            ans += 1;
            if(v1.back() <= v2.back()){
                v1.push_back(x);
            }else{
                v2.push_back(x);
            }
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