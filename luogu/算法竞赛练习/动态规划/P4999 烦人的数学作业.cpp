#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
typedef long long ll;
const int Mod = 1e9 + 7;
int n;
string s;
int dp[20][200];

int f(int i,int sum,int isLimit,int isNum){
    if(i == n) return sum % Mod;
    if(!isLimit && dp[i][sum] != -1) return dp[i][sum];

    int res = 0;
    int up = isLimit ? s[i] - '0' : 9;
    for(int d=0;d<=up;d++)
        res = (res + f(i+1,sum+d,isLimit&(d==up),isNum)) % Mod;

    if(!isLimit) dp[i][sum] = res; 
    return (res + Mod) % Mod;
}

int check(int x){
    s = to_string(x);
    int sum = 0;
    for(auto &c : s) sum += (c - '0');
    return sum % Mod;
}

void solve(){
    int l,r; cin>>l>>r;
    s = to_string(r); n = s.length(); memset(dp,-1,sizeof dp); int ansr = f(0,0,1,0);
    s = to_string(l); n = s.length(); memset(dp,-1,sizeof dp); int ansl = f(0,0,1,0);
    cout << (ansr - ansl + check(l) + Mod) % Mod << "\n";
}

signed main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
