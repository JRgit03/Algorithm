#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e5 + 10;
int n,k;
string s;

void solve(){
    cin>>k>>s; 
    n = s.length(); s = "?" + s;
    int m = n / k; // 循环节长度
    if(k == 1){
        cout << 0 << "\n";
        return;
    }    
    if(n % k != 0 || k > n){
        cout << -1 << "\n";
        return;
    }
    int ans = 0;
    for(int i=1;i<=m;i++){
        vector<int> vec(26); int cnt = 0;
        for(int j=i;j<=n;j+=m) {
            cnt += 1;
            vec[s[j] - 'a'] += 1;
        }
        int maxx = 0;
        for(auto &x : vec) maxx = max(maxx, x);
        ans += cnt - maxx;
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
