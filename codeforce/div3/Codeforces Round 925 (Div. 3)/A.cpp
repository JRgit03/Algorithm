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

map<int,vector<string>> mp;

void init(){
    string s = "";
    for(char c1 = 'a'; c1 <= 'z'; c1++){
        for(char c2 = 'a'; c2 <= 'z'; c2++){
            for(char c3 = 'a'; c3 <= 'z'; c3++){
                s = ""; s += c1; s += c2; s += c3;
                int x = c1 - 'a' + c2 - 'a' + c3 - 'a' + 3;
                mp[x].push_back(s);
            }
        }
    }
    for(auto &[_,v] : mp) sort(v.begin(), v.end(), [&](auto &p, auto &q){
        return p < q;
    });
}

void solve(){
    int x; cin>>x;
    cout << mp[x][0] << "\n";
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
