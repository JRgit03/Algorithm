#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int a[N],pre[N];

void solve(){
    int n; cin>>n;
    vector<int> ans(2);
    for(int i=1;i<=n;i++) cin>>a[i];
    string s; cin>>s; s = "?" + s;
    for(int i=1;i<=n;i++){
        ans[s[i] - '0'] ^= a[i];
        pre[i] = pre[i-1] ^ a[i];
    }
    int m; cin>>m;
    for(int i=0;i<m;i++){
        int op,l,r;cin>>op>>l;
        if(op == 1){
            cin>>r;
            int t = pre[r] ^ pre[l-1];
            ans[0] ^= t , ans[1] ^= t;
        }else{
            cout << ans[l] << " ";
        }
    }
    cout << "\n";
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
