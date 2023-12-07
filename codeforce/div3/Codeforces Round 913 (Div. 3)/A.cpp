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
    string s; cin>>s;
    char x = s[0]; int y = s[1] - '0';
    for(char c = 'a'; c <= 'h'; c += 1){
        if(c == x) continue;
        cout << c << y << "\n";
    }
    for(int i=1;i<=8;i++){
        if(i == y) continue;
        cout << x << i << "\n";
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
