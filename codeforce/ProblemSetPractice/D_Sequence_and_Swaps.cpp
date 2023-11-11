#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e2 + 10;
int n,x;
int a[maxn];

bool check(){
    for(int i=2;i<=n;i++)
        if(a[i] < a[i-1])
            return false;
    return true;
}

void solve(){
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(check()){
        cout << 0 << "\n";
        return;
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(a[i] > x){
            swap(a[i],x);
            ans += 1;
        }
        if(check()){
            cout << ans << "\n";
            return;
        }
    }
    cout << -1 << "\n";
    return;
}

int main(){
    int t; cin>>t;
    while(t--)
        solve();
    return 0;
}
