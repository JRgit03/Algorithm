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
    int n; cin>>n; int m = n * 2; char wp; cin>>wp;
    vector<string> v;
    map<char,vector<string>> mp;
    for(int i=0;i<m;i++){
        string s; cin>>s;
        if(s[1] == wp) v.push_back(s);
        else mp[s[1]].push_back(s);
    }
    sort(v.begin(), v.end(), [&](auto &p, auto &q){
        return p[0] < q[0];
    });
    int x = v.size(), y = 0;
    for(auto &[_, v] : mp) {
        y += v.size();
        sort(v.begin(), v.end(), [&](auto &p, auto &q){
            return p[0] < q[0];
        });
    }
    if(x >= y){
    	// debug(x);
        vector<string> t;
        for(auto &[_, v] : mp) 
            for(auto s : v)
                t.push_back(s);
        vector<pair<string,string>> ans(n);
        for(int i=0;i<y;i++) ans[i] = {t[i], v[i]};
        int id = y;
        for(int i=y;i<v.size();i+=2) ans[id++] = {v[i], v[i+1]};
        for(auto [a,b] : ans) cout << a << " " << b << "\n";
    }else{
        int dif = y - x;
        int sum = 0;
        vector<pair<string,string>> ans;
        vector<string> other;
        for(auto &[_, arr] : mp){
            int sz = arr.size();
         	// debug(sz);
            sum += sz / 2 * 2;
            for(int i=0;i<sz-1;i+=2){
                ans.push_back({arr[i], arr[i+1]});
            }
            if(sz & 1) other.push_back(arr.back());
            // debugsq(arr);
        }
        if(sum >= dif){
            int ne = other.size();
            for(int i=0;i<other.size();i++) ans.push_back({other[i], v[i]});
            for(int i=ne;i<v.size();i+=2) ans.push_back({v[i], v[i+1]});
            for(auto [a,b] : ans) cout << a << " " << b << "\n";
        }else{
            cout << "IMPOSSIBLE" << "\n";
        }
    }
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
