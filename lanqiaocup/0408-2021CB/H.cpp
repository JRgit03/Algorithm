#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b) { return (a > b ? a : b);}
int min(int a,int b) { return (a < b ? a : b);}

const int N = 3e3 + 10;
int c[N][N];

unordered_map<int,int> mp;

void solve(){
    int n; cin>>n;
    memset(c, 0, sizeof c);
    int t = 0;
    for(int i=1;i<=60;i++){
        for(int j=1;j<=i;j++){
            t += 1;
            if(i == 1 && j == 1) c[i][i] = 1;
            else c[i][j] = c[i-1][j] + c[i-1][j-1];
            if(!mp.count(c[i][j])) mp[c[i][j]] = t;
        }
    }
    int ans = mp.count(n) ? mp[n] : 1e18;
    ans = min(ans, n * (n + 1) / 2 + 2);
    cout << ans << "\n";
}

signed main(){
    IOS; solve();
    return 0;
}

