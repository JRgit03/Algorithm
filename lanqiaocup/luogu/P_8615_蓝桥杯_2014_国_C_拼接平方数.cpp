#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

int f(string s){
    int cnt = 0;
    for(auto &c : s) cnt += (c == '0');
    if(cnt == s.length()) return 0;
    int x = stoi(s), c = sqrt(x);
    return c * c == x;
}

int check(int num){
    string s = to_string(num); 
    int n = s.length(), m = n - 1;
    if(m == 0) return f(s);
    int suc = 0;
    for(int i=1;i<=m;i++) {
        string pre = s.substr(0, i), suf = s.substr(i);
        suc |= (f(pre) && f(suf)); 
    } 
    return suc;
}

void solve(){
    int l,r; cin>>l>>r;
    for(int i=l;i<=r;i++) if(f(to_string(i)) && check(i)) {
        cout << i << "\n";
    }    
}

signed main(){
    IOS;
    solve();
    return 0;
}
