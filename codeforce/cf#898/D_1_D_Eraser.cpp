#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve(){
    int n,k; cin>>n>>k;
    string s; cin>>s;
    int ans = 0;
    for(int r=0;r<n;r++){
        if(s[r] == 'B'){
            ans += 1;
            r += k - 1;
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
