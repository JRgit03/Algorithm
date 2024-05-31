#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e6 + 10;

void solve(){
    string s; cin>>s;
    string p = s; int ans = 0;
    sort(p.begin(), p.end());
    do{
        if(p == s) break;
        ans += 1;
    }while(next_permutation(p.begin(), p.end()));
    cout << ans << "\n";
}

signed main(){
    // string s = "0123456789";
    // int cnt = 0;
    // do{cnt += 1;}while(next_permutation(s.begin(), s.end()));
    // cout << cnt << "\n"; 3628800
    IOS;
    solve();
    return 0;
}
