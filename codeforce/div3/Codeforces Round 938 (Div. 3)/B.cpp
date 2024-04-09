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
    int n,c,d; cin>>n>>c>>d;
    vector<int> a(n*n); for(auto &x : a) cin>>x;
    sort(a.begin(), a.end());
    // debugsq(a);
    vector<vector<int>> b(n, vector<int>(n)); 
    int suc = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == 0 && j == 0) b[i][j] = a[0];
            else {
                if(i-1>=0 && j-1>=0){
                    int r1 = b[i][j-1] + d, r2 = b[i-1][j] + c;
                    if(r1 != r2) suc = 0;
                    else b[i][j] = r1;
                }else if(j-1>=0 ) b[i][j] = b[i][j-1] + d;
                else if(i-1>=0) b[i][j] = b[i-1][j] + c;
            }
        }
    }
    vector<int> vec; 
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            vec.push_back(b[i][j]);
    sort(vec.begin(), vec.end());
    // debugsq(vec);
    cout << (a == vec && suc ? "YES" : "NO") << "\n";
}

signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
