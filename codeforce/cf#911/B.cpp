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
    int a,b,c; cin>>a>>b>>c;
    auto check = [&](int a,int b,int c){
        // return  abs(b-c) % 2 == 0 || (a + min(b,c) >= abs(b-c) * 2 && (abs(b - c) % 2 == 0));  
        return abs(b-c) % 2 == 0;
    };
    cout << (check(a,b,c) ? 1 : 0) << " ";
    cout << (check(b,a,c) ? 1 : 0) << " ";
    cout << (check(c,a,b) ? 1 : 0) << " ";
    cout << "\n";
}

signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
