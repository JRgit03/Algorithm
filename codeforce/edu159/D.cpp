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
    int n,q; cin>>n>>q;
    string s; cin>>s; int px = 0, py = 0; 
    vector<PII> vec(n+1);  vec[0] = {0,0};
    map<PII,vector<int>> pos; // pos[point,[到达时间戳集合...]] 
    pos[vec[0]].push_back(0);
    for(int i=0;i<n;i++){
        char c = s[i];
        if(c == 'U') py++;
        else if(c == 'D') py--;
        else if(c == 'L') px--;
        else px++;
        vec[i+1] = {px,py};
        pos[{px,py}].push_back(i+1);

    }
    auto check = [&](int x,int y,int l,int r){
        if(l > r) return false;
        if(!pos.count({x,y})) return false;
        int L = 0, R = pos[{x,y}].size() - 1;
        while(L < R){
            int mid = L + R >> 1;
            if(pos[{x,y}][mid] >= l) R = mid;
            else L = mid + 1;
        }
        return pos[{x,y}][R] >= l && pos[{x,y}][R] <= r;
    };
    while(q--){
        int x,y,l,r; cin>>x>>y>>l>>r;
        auto [a,b] = vec[l-1];
        auto [c,d] = vec[r]; 
         cout << (check(x,y,0,l-1) || check(x,y,r,n) || check(a+c-x,b+d-y,l-1,r) ? "YES" : "NO") << "\n";
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
