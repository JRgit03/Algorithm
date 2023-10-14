#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve(){
    int n; cin>>n;
    vector<string> g(n);
    for(int i=0;i<n;i++) cin>>g[i];
    int ans = 0;
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n/2;j++){
            vector<int> vec;
            vec.push_back(g[i][j]-'a');
            vec.push_back(g[j][n-1-i]-'a');
            vec.push_back(g[n-1-i][n-1-j]-'a');
            vec.push_back(g[n-1-j][i]-'a');
            sort(vec.begin(),vec.end(),greater<int>());
            for(int i=1;i<4;i++) ans += vec[0] - vec[i];
        }
    }
    cout << ans << "\n";
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
