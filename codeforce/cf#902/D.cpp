#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define dbug(x) cout << #x << '=' << x << endl
#define int long long
#define x first
#define y second
#define ONLINE_JUDGE  
using namespace std;
const int N = 1e5 + 10, Mod = 1e9 + 7, INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
typedef pair<int,int> PII;
typedef long long ll;

void solve(){
    int n,c; cin>>n>>c;
    int sum; cin>>sum;
    vector<PII> vec;
    for(int i=2;i<=n;i++) {
        int x; cin>>x;
        vec.push_back({x,i});
    }
    sort(vec.begin(),vec.end(),[&](PII &a,PII &b){
        return a.x - a.y * c > b.x - b.y * c;
    });
    for(auto [a,b] : vec){
        if(sum + a >= b * c){
            sum += a;
        }else{
            cout << "No" << "\n";
            return;     
        }
    }
    cout << "Yes" << "\n";
    return;
}

signed main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}

// ai + aj >= i * j * c  (i >= 2 && j >= 2 && i != j)
// 假设 i j 不能与 1 相连
// a1 + ai < i * c
// a1 + aj < j * c
// => (i + j) * c > i * j * c 显然不成立 i j >= 2 
