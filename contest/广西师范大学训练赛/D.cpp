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
    int n; cin>>n;
    vector<tuple<int,int,int>> vec(n);
    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        vec[i] = {a,b,i};
    }
    sort(vec.begin(),vec.end(),[&](auto &p,auto &q){
       auto [a1,b1,c1] = p;
       auto [a2,b2,c2] = q;
       if(a1 * (a2 + b2) != a2 * (a1 + b1)) return  a1 * (a2 + b2) > a2 * (a1 + b1);
       return c1 < c2;
    });
    for(auto [a,b,c] : vec) cout << c+1 << " ";
}

signed main(){
    IOS; solve();
    return 0;
}
