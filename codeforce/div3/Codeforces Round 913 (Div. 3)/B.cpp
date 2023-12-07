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
    int n = s.length();
    vector<int> del(n),v1,v2;
    for(int i=0;i<n;i++){
        char c = s[i];
        if(c == 'B'){
            del[i] = 1;
            if(v2.size()){
                del[v2.back()] = 1;
                v2.pop_back();
            }
        }else if(c == 'b'){
            del[i] = 1;
            if(v1.size()){
                del[v1.back()] = 1;
                v1.pop_back();
            }
        }else{
            if(c >= 'a' && c <= 'z') v1.push_back(i);
            else v2.push_back(i);
        }
    }    
    string ans = "";
    for(int i=0;i<n;i++) if(!del[i]) ans += s[i];
    cout << ans << "\n";
}

signed main(){
    IOS;
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
