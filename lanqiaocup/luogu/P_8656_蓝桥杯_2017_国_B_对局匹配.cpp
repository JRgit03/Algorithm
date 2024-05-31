#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e5 + 10, maxn = 1e5;
int n,k;
int a[N];
int b[N];

void solve1(){
    //cerr << "?" << "\n";
    int ans = 0;
    for(int i=0;i<(1<<n);i++){
        map<int,int> mp; int suc = 1, cnt = 0;
        for(int j=0;j<n;j++){
            if((i >> j) & 1) {
                cnt += 1;
                if(mp.count(a[j + 1] - k) || mp.count(a[j + 1] + k)) suc = 0;
                mp[a[j + 1]] = 1;
            }
        }
        //cerr << i << " " << suc << " " << cnt << "\n";
        if(suc) ans = max(ans, cnt);
    }
    cout << ans << "\n";
}


int w[N];
int dp[N],cnt;

void solve2(){
    int ans = 0;
    for(int i=0;i<k;i++){
        cnt = 0;
        for(int j=i;j<=maxn;j+=k){
            cnt += 1;
            w[cnt] = b[j];
            dp[cnt] = 0;
        }
        for(int j=1;j<=cnt;j++) {
            dp[j] = dp[j - 1];
            dp[j] = max(dp[j], (j - 2 >= 0 ? dp[j - 2] : 0) + w[j]);
        }
        ans += dp[cnt];
    }
    cout << ans << "\n";
}

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>a[i]; b[a[i]] += 1;
    }    
    if(k == 0){
        int ans = 0;
        for(int i=0;i<=maxn;i++) ans += (b[i] > 0);
        cout << ans << "\n";
        return; 
    }
    if(n <= 10) solve1();
    else solve2();
}

signed main(){
    IOS;
    solve();
    return 0;
}
