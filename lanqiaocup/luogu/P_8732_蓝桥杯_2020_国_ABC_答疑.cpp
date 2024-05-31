#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e3 + 10, INF = 0x3f3f3f3f3f3f3f3f;
int n;
struct Node{
    int s,a,e;
    bool operator < (const Node& o) const {
        return s + a + e < o.s + o.a + o.e;
    }
}vec[N];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>vec[i].s>>vec[i].a>>vec[i].e;
    int ans = INF;
    for(int i=1;i<=n;i++){
        vector<Node> tmp;
        for(int j=1;j<=n;j++) {
            if(i == j) continue;
            tmp.push_back(vec[j]);
        }
        sort(tmp.begin(), tmp.end());
        int res = 0, pre = 0;
        for(int j=0;j<n-1;j++){
            pre += tmp[j].s + tmp[j].a;
            res += pre;
            pre += tmp[j].e;
        }
        res += pre + vec[i].s + vec[i].a;
        ans = min(ans, res);
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
