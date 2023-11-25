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

const int maxx = 1e12;

__int128 fastpow(__int128 a,__int128 b){
    __int128 res = 1;
    while(b){
        if(b & 1) res = res * a;
        if(res > maxx) return -0x3f3f3f3f3f3f3f3f;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve(){
    vector<int> vec(3); for(auto &x : vec) cin>>x;
    set<int> st;
    sort(vec.begin(),vec.end()); 
    int sz1 = 0;
    for(auto x : vec) sz1 += (x == 1);
    if(sz1 == 0){
        for(int i=0;i<=41;i++){
            if(fastpow(vec[0],i) < 0) break;
            for(int j=0;j<=41;j++){
                if(fastpow(vec[1],j) < 0) break;
                for(int k=0;k<=41;k++){
                    if(fastpow(vec[2],k) < 0) break;
                    int res = fastpow(vec[0],i) + fastpow(vec[1],j) + fastpow(vec[2],k);
                    if(res > maxx) break;
                    st.insert(res);
                }
            }
        }
    }else if(sz1 == 1){
        for(int i=0;i<=41;i++){
            if(fastpow(vec[1],i) < 0) break;
            for(int j=0;j<=41;j++){
                if(fastpow(vec[2],j) < 0) break;
                int res = fastpow(vec[1],i) + fastpow(vec[2],j) + 1;
                if(res > maxx) break;
                st.insert(res);
            }
        }
    }else if(sz1 == 2){
        for(int i=0;i<=41;i++){
            if(fastpow(vec[2],i) < 0) break;
            int res = fastpow(vec[2],i) + 1 + 1;
            if(res > maxx) break;
            st.insert(res);
        }
    }
    // for(auto &x : st) cout << x << "\n"; cout << "----" << "\n";
    vector<int> v;
    for(auto x : st) v.push_back(x);
    int q; cin>>q;
    while(q--){
        int x; cin>>x;
        int l = 0, r = v.size() - 1;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(v[mid] <= x) l = mid;
            else r = mid - 1; 
        }
        int k = r; //一定存在
        // cout << k << "\n";
        l = k, r = v.size() - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(v[mid] - v[k] != mid - k) r = mid;
            else l = mid + 1;
        }
        // cout << r << " " << v[r] << "\n";
        cout << v[r-1] + 1 << " " << v[r] - (v[r-1] + 1) << "\n";
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
