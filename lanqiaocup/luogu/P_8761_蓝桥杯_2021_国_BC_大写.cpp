#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e6 + 10;

void solve(){
    string s; cin>>s;
    for(auto &c : s) if(c >= 'a' && c <= 'z') {
        c = c - 'a' + 'A';
    }
    cout << s << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
