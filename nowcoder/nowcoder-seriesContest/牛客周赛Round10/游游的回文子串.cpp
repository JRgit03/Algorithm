#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define int long long
using namespace std;
typedef long long ll;
const int N = 1e3 + 10 , Mod = 1e9 + 7;
int n;
int a[N];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    int ans = 0;
    for(int i=1;i<=n;i++){
        int l = i , r = i;
        while(l>=1 && r<=n) {
            if(l == r) ans = (ans + (1 + a[i]) * a[i] / 2) % Mod , l-- , r++;
            else if(a[l] == a[r]) ans = (ans + a[l]) % Mod , l-- , r++;
            else if(a[l] != a[r]){
                ans = (ans + min(a[l] , a[r])) % Mod; break;
            }
        }
    }    
    cout << ans << "\n";
}

signed main(){
    IOS; solve();
    return 0;
}
