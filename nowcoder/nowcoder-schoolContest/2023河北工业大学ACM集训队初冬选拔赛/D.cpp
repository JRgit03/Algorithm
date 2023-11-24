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
const int maxn = 1e3 + 10;

int s[maxn][maxn];
int a[maxn][maxn];
int b[maxn][maxn];

void add(int x1,int y1,int x2,int y2){
    s[x1][y1] += 1, s[x2+1][y1] -= 1, s[x1][y2+1] -= 1, s[x2+1][y2+1] += 1;
}

int query(int x1,int y1,int x2,int y2){
    return a[x2][y2] - a[x1-1][y2] - a[x2][y1-1] + a[x1-1][y1-1];
}

void solve(){
    int n,k,l; cin>>n>>k>>l;
    for(int i=1;i<=n;i++){
        int x1,y1; cin>>x1>>y1;
        int x2 = x1 + k - 1, y2 = y1 + k - 1;
        add(x1,y1,x2,y2);
    }
    for(int i=1;i<=l;i++)   
        for(int j=1;j<=l;j++)
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + s[i][j];
    for(int i=1;i<=l;i++)   
        for(int j=1;j<=l;j++)
            a[i][j] = (a[i][j] > 0);
    for(int i=1;i<=l;i++)   
        for(int j=1;j<=l;j++)
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + a[i][j];
    // for(int i=1;i<=l;i++)   
    //     for(int j=1;j<=l;j++)
    //         cout << a[i][j] << " \n"[j == l];
    int q; cin>>q;
    while(q--){
        int x1,y1; cin>>x1>>y1;
        int x2 = x1 + k - 1, y2 = y1 + k - 1;
        // cout << query(x1,y1,x2,y2) << "\n";
        cout << k * k - query(x1,y1,x2,y2) << "\n";
    }
}  

signed main(){
    IOS;
    int T=1;
    // cin>>T;
    while(T--)
        solve();
    return 0;
}
