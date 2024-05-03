#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
const int N = 5e2 + 10;

#ifdef LOCAL
#include "../../../algorithm-template/debug.h"
#else
#define debug(...) 42
#endif

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

string str[3] = {"?","?COFFEE", "?CHICKEN"};
vector<array<int,4>> s(N);

string dfs(int i,int l,int r){
    debug(i,l,r);
    if(l > r) return "";
    if(i > 80) return dfs(i-2,l,r);
    if(i == 1 || i == 2){
        string res = "";
        for(int j=l;j<=min(r,str[i].length()-1);j++) {
            res += str[i][j];
        }
        return res;
    }
    auto [a,b,c,d] = s[i];
    string ans = "";
    if(l <= b) ans += dfs(i-2,l,min(r,b));
    if(r >= c) ans += dfs(i-1,max(l,c)-b,r-b);
    return ans;
}

void solve(){
    int n,k; cin>>n>>k;
    int l = k, r = k + 10 - 1;
    cout << dfs(n, l, r) << "\n";
}

signed main(){
    IOS;
    s[1] = {1,6,1,6};
    s[2] = {1,7,1,7};
    for(int i=3;i<=80;i++) {
        s[i] = {1, s[i-2][3], s[i-2][3]+1, s[i-2][3]+1+s[i-1][3]-1};
        debug(s[i]);
    }
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}
