#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e5 + 10;
int n;
int a[N];
int b[N];

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        b[a[i]] += 1;
    }     
    int ans = 0, cnt1 = 0, cnt3 = 0;
    for(int i=1;i<=n;i++){
        if(b[i] == 1) cnt1 += 1;
        else if(b[i] > 2) cnt3 += b[i] - 2; 
    }
    if(cnt1 >= cnt3) ans = (cnt1 - cnt3) / 2 + cnt3;
    else ans = cnt3;
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
