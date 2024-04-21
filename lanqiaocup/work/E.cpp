#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){ return a > b ? a : b;}
int min(int a,int b){ return a < b ? a : b;}

const int N = 1e3 + 10, M = 1e5 + 10, INF = 0x3f3f3f3f3f3f3f3f;
int n,m,up;
string s,t;
int dp[M][N];

vector<int> vec[1100];

void solve(){
    cin>>n>>m>>up;
    cin>>s>>t; s = "?" + s; t = "*" + t;
    memset(dp, 0x3f, sizeof dp);
    int ans = 0;
    for(int i=1;i<=n;i++) {
        if(s[i] == t[1]) dp[1][i] = 0;
        vec[s[i]-'a'].push_back(i); 
        if(dp[1][i] != INF) ans = 1;
    }
    for(int i=2;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[j] == t[i]){
                int l = 0, r = vec[t[i-1]-'a'].size() - 1;
                if(r == -1) continue;
                while(l < r){
                    int mid = l + r + 1 >> 1;
                    if(vec[t[i-1]-'a'][mid] <= j) l = mid;
                    else r = mid - 1;
                }
                int k = vec[t[i-1]-'a'][r];
                if(k <= j) dp[i][j] = min(dp[i][j], dp[i-1][k] + abs(k - j));
                
                l = 0, r = r = vec[t[i-1]-'a'].size() - 1;
                while(l < r){
                    int mid = l + r >> 1;
                    if(vec[t[i-1]-'a'][mid] >= j) r = mid;
                    else l = mid + 1;
                }
                k = vec[t[i-1]-'a'][r];
                if(k >= j) dp[i][j] = min(dp[i][j], dp[i-1][k] + abs(k - j));
            }
            if(dp[i][j] != INF && dp[i][j] <= up) ans = i; 
        }
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
} 

/*
3 6 5
abc
acbbac

5
*/

/*
3 2 2
abc
ac
*/

/*
3 2 2
cba
ac
*/
