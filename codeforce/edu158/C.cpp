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

const int fk = 1e18;

int n; 
set<int> st1,st2;

void solve(){
    st1.clear(); st2.clear(); 
    cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        st1.insert(x);
    }
    vector<int> op;
    auto output = [&](){
    	int ans = op.size();
    	cout << ans << "\n";
        if(ans <= n){
            for(auto x : op) cout << x << " ";
            cout << "\n";
        }
    };
    while(1){
        if(st1.size() == 1){    
            output(); return;
        }
        if(st1.size() == 2){
            vector<int> v(2); int idx = 0;
            for(auto x : st1) v[idx++] = x;
            if(v[0]+1 == v[1]){
                op.push_back(v[0]);
                output(); return;
            }
        }
        // auto it = --st1.end();
        auto it = st1.begin();
        op.push_back(*it);
        for(auto x : st1) st2.insert((x+*it)/2);
        swap(st1,st2); st2.clear();
        // for(auto x : st1) cout << x << " "; cout << "\n";
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
