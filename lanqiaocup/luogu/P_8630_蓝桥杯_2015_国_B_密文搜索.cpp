#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e6 + 10;
int n;
int ans;
string s,t;
map<string, int> cnt;

void solve(){
    cin>>s;
    for(int i=0;i<s.length();i++){
        string tmp = s.substr(i, 8);
        sort(tmp.begin(), tmp.end());
        cnt[tmp] += 1;
    }
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        sort(t.begin(), t.end());
        ans += cnt[t];
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
