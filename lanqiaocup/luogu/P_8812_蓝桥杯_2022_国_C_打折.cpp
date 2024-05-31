#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e5 + 10, INF = 0x3f3f3f3f3f3f3f3f;
int n,m;

struct Node{
    int s,t;
    double p;
    int b;
};

map<int, vector<Node>> mp;


// AC 40/100
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int s,t,p,c; cin>>s>>t>>p>>c;
        while(c--){
            int a,b; cin>>a>>b;
            mp[a].push_back({s,t,1.0*p/100,b});
        }
    }
    double ans = 1e18;
    for(int d=1;d<=100;d++){
        int res = 0;
        for(auto &[id, vec] : mp){
            double minn = 1e9;
            for(auto &[s,t,p,b] : vec){
                if(d >= s && d <= t) minn = min(minn, p * b);
                else minn = min(minn, b); 
            }
            res += minn;
        }
        ans = min(ans, res);
    }
    cout << (long long)ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
