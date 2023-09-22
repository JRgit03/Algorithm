#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve(){
    int ans = 0;
    for(int i=1;i<=10;i++){
        string s; cin>>s;
        for(int j=1;j<=10;j++){
            char c = s[j-1];
            int x = i , y = j;
            if(c == 'X'){
                if(x >= 6) x = 11 - x;
                if(y >= 6) y = 11 - y;
                ans += min(x,y);
            }
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
