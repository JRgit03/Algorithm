#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e3 + 10, M = 2e4 + 10;
int n, m = 20000;
struct Node{
    int w,v;

    bool operator < (const Node& o) const {
        return w + v < o.w + o.v;
    }
}vec[N];
int dp[M];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>vec[i].w>>vec[i].v;
    sort(vec + 1, vec + 1 + n);
    int ans = 0;
    for(int i=1;i<=n;i++){
        // cout << vec[i].w << " " << vec[i].v << "\n";
        for(int j=m;j>=0;j--){
            if(j - vec[i].w <= vec[i].v && j - vec[i].w >= 0) 
                dp[j] = max(dp[j], dp[j - vec[i].w] + vec[i].v);
            ans = max(ans, dp[j]);
        }
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    //cerr << 1LL * 256 * 1024 * 1024 * 8 / 64 << "\n"; // 3e7 滚动数组优化
    solve();
    return 0;
}
