#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

#ifdef LOCAL
#include "./debug.h"
#else
#define debug(...) 21
#endif

int max(int a,int b){return a > b ? a : b;}

const int N = 1e3 + 10, M = 5e3 + 10;
int n,m,k;
int last[N]; 
int dp[N][M]; 
// last[i]????i????????????k???j
// dp[i,j]???i????????j?????
// dp[i][j] = dp[i-1][j]
// dp[i][j] = dp[last[i]][j - val[i]] + val[i];
int s[13];
set<int> st = {1,3,5,7,8,10,12};

struct Node{
    int day,val;
    bool operator < (const Node& o) const {
        return day < o.day;
    }
}vec[N];

void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=12;i++){
        if(i == 2) s[i] = s[i-1] + 28;
        else s[i] = s[i-1] + (st.count(i) ? 31 : 30);
    }
    for(int i=1;i<=n;i++){
        int m,d,v; cin>>m>>d>>v;
        vec[i] = {s[m - 1] + d, v};
    }
    sort(vec + 1, vec + 1 + n);
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            if(vec[i].day - vec[j].day >= k){
                last[i] = j;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = dp[i-1][j];
            if(j - vec[i].val >= 0) dp[i][j] = max(dp[i][j], dp[last[i]][j - vec[i].val] + vec[i].val);
        }
    }
    cout << dp[n][m] << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
