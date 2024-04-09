#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << (x) << '\n'
#define debugsq(x) cerr << #x << ": ["; for (auto i : x) cerr << i << ' '; cerr << "]\n";
#define debugmp(x) cerr << #x << ": [ "; for (auto [i, j] : x) cerr << '[' << i << "," << j << "] "; cerr << "]\n";
#define int long long
using namespace std;
const int mod = 1e9 + 7;

int fastpow(int a,int b){
    int res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res % mod;
}

void solve(){
    int n,p; cin>>n>>p;
    vector<int> vec(n); for(auto &x : vec) cin>>x;
    if(p == 1){
        cout << (n & 1) << "\n";
        return;
    }
    sort(vec.begin(), vec.end(), greater<int>());
    // debugsq(vec);
    int s1 = 0, s2 = 0;
    for(int i=0;i<n;i++){
        // debug(i);
        s1 += fastpow(p, vec[i]);
        s1 %= mod;
        int j = i+1;
        int num = vec[i], ne = 1, s = 0;
        while(j < n && ne > 0){
            while(vec[j] != num && ne * p <= n - j) num -= 1, ne *= p;
            if(vec[j] == num) ne--;
            s += fastpow(p, vec[j]);
            s %= mod;
            j += 1;
            if(ne == 0){
                s1 -= fastpow(p, vec[i]);
                s1 %= mod;
                s = 0;
            }
        }
        s2 += s;
        s2 %= mod;
        i = j - 1;
    }
    cout << ((s1 - s2) % mod + mod) % mod << "\n";
}

signed main(){
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
