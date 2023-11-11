#include <bits/stdc++.h>
#define int long long
using namespace std;

string toBase3(int x){
    string s = "";
    while(x){
        s = char(x % 3 + '0') + s;
        x /= 3;
    }
    return s;
}

int calc(string x){
    int res = 0;
    for(auto c : x) res += c - '0';
    return res;
}

int to10(string x){
    int res = 0;
    for(auto c : x) res = res * 3 + c - '0';
    return res;
}

void solve(){
    int l,r; cin>>l>>r; 
    string L = toBase3(l), R = toBase3(r);
    for(int i=0;i<R.length()-L.length();i++) L = '0' + L;
    int m = R.length(), ans = m + calc(R);
    for(int i=0;i<m;i++){
        if(R[i] == '0') continue;
        string tmp = R; tmp[i] = tmp[i] - 1;
        for(int j=i+1;j<m;j++) tmp[j] = '2';
        int k = 0; while(tmp[k] == '0') k++;
        tmp = tmp.substr(k);
        if(to10(tmp) >= l) ans = max(ans, calc(tmp) + (int)tmp.length());
    }
    cout << ans << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--)
        solve();
    return 0;
}
