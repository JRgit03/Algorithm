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

int n;
int a[N],b[N];

void solve(){
    cin>>n;
    string s; cin>>s; for(int i=0;i<n;i++) a[i+1] = (s[i] == '1');
    for(int k=n;k>=1;k--){
        for(int i=0;i<=n;i++) b[i] = 0;
        for(int i=1,sum=0;i+k-1<=n;i++){
            sum += b[i];
            if((a[i] + sum + 1) & 1){
                b[i] += 1, b[i+k-1+1] -= 1;
                sum += 1;
            }
        }
        int suc = 1;
        for(int i=1,sum=0;i<=n;i++) {
            sum += b[i];
            suc &= ((a[i] + sum) & 1);
        }
        if(suc){
            cout << k << "\n";
            return;
        }
    }
}

signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
