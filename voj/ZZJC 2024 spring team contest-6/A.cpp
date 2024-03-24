#include <bits/stdc++.h>
#define int long long
using namespace std;

int fastpow(int a,int b){
    int res = 1;
    while(b){
        if(b & 1) res = res * a % 26;
        a = a * a % 26;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n,m; cin>>n>>m;
    string s; cin>>s;
    int p = fastpow(10, 100); //cout << p << "\n"; 16
    vector<char> ans;
    vector<int> vec = {p,p-1};
    for(int i=2;i<=20;i++){
        int x = (1 << i);
        int y = x >> 1;
        int z = y >> 1;
        vector<int> tmp; int len = vec.size();
        if(z) for(int j=z;j>0;j--) tmp.push_back(vec[len - j]);
        for(int j=0;j<z;j++) tmp.push_back((tmp[j] - 1 + 26) % 26);
        for(auto &v : tmp) vec.push_back(v);
    }
    // for(int i=0;i<100;i++) cout << vec[i] << " "; cout << "\n";
    int k = 0;
    for(int i=0,j=n-1;i<m;i++){
        char c = char((s[j] - 'a' + vec[k]) % 26 + 'a');
        ans.push_back(c);
        j -= 1;
        if(j == n / 2 - 1) {
            j = n - 1;
            k += 1;
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto &c : ans) cout << c;
}
// wrwx rwx sxy

signed main(){
    solve();
    return 0;
}
