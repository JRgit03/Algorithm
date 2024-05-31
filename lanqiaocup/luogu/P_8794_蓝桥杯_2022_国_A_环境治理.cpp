#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e2 + 10, up = 1e9;
int n,q;
int d[N][N];
int dp[N][N];
int l[N][N];

int check(int k){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            dp[i][j] = max(l[i][j], d[i][j] - (k / n + (i <= (k % n))) - (k / n + (j <= (k % n))));
        }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    int sum = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            sum += dp[i][j];
    return sum <= q;
}

void solve(){
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>d[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>l[i][j];
    int l = 0, r = 1e9;
    while(l < r){
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }

    if(check(r)) cout << r << "\n";
    else cout << -1 << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
