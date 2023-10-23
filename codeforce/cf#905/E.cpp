#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
// #define ONLINE_JUDGE  
#define int long long
using namespace std;
typedef long long ll;

// 不操作数 防止过大 相对
void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int ans = 0 , m = 0;
    for(int i=1;i<n;i++){ 
        if(a[i] < a[i-1]){
            int t = a[i];
            while(t < a[i-1]){
                t <<= 1;
                m++;
            }
        }else if(a[i] >= a[i-1]){
            int t = a[i-1];
            while(a[i] >= t * 2 && m > 0){ 
                t <<= 1;
                m--;
            }
        }
        ans += m;
    }
    cout << ans << "\n";
}

signed main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
